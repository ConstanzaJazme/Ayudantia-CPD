/*
 *Programa que paraleliza funciones de: llenar arreglo, obtener promedio, varianza y desviación estandar
 *Autor: Constanza Jazme
 *Fecha: 11-05-2019
 *
 **/

#include<mpi.h>
#include<math.h>
#include<stdio.h>

/** Funcion para generar numeros aleatorios */

int aleatorio(){
        int random;
        random=1+rand()%501;
        return random;
}

/*Función para llenar arreglo principal*/

void llenar_vec(int vec[]){
        for (int i=0; i<100000; i++){
                vec[i]=aleatorio();
        }
}

/**Función para crear sub vector*/

int* create_sub_vec(int begin, int end, int* origin){
    int* sub_vec;
    int size;
    int aux = 0;
    size = end - begin;
    sub_vec = (int*)malloc(size * sizeof(int));
    for (int i = begin; i < end; ++i) {
        *(sub_vec+aux) = *(origin+i);
        aux += 1;
    }
    return  sub_vec;
}


/**Función para obtener el promedio de un subvector**/

float obtener_sub_prom(int largo, int* sub_vec){ /* Se ingresa a la función: el inicio del sub_vec, el fin, el sub_vec y el vector con datos*/
  float sub_prom=0.0;  /* variable en donde se almacenará el promedio del sub vector*/
  float sum=0.0;    /* Suma de los elementos del vector*/

  for (int i = 0; i < largo; ++i) {   /* Recorre desde posicion inicial a posición final del sub vector*/
      sum=sum+*(sub_vec+i);   /* Obtiene valores almacenados en el sub vector */
  }

  sub_prom=sum/largo; /*Obtiene el sub promedio*/
  return sub_prom;

}

/* Función para obtener diferencias al cuadrado (entre elemento del arreglo con el promedio) */

double obtener_dif_cuadrada(float p, int largo, int* sub_vec){
  float diferencia= 0.0;
  double sum=0.0;
  for (int i=0; i<largo; i++){
    diferencia=*(sub_vec+i)-p;
    sum=sum+(diferencia*diferencia);
  }
  return sum;
}

/**Funcion para calcular desviacion estandar*/

float desv(float v){
	float  d=sqrt(v);
	return d;
}

/*Función que imprime todos los valores de un sub vector*/

void print(int my_rank, int comm_sz, int n_over_p, int* sub_vec){
    printf("Process %d out of %d received sub_vecotr: [ ", my_rank, comm_sz);
    for (int i = 0; i < n_over_p; ++i)
    {
        printf("%d, ", *(sub_vec+i));
    }
    printf("]\n");
}

int main(void){
  srand(time(NULL));
  int mi_rango; /* rango del proceso    */
  int p; /* numero de procesos   */
  int tag = 0; /* etiqueta del mensaje */


  int div_conjunto; /* n sobre p, indica en cuantos datos contiene un conjunto ideal (simetrico con los demás)*/
  int vec[100000]; /* Declaración del arreglo*/
  int* sub_vec = NULL;
  float sub_prom=0;
  float prom=0.0;
  double sumatoria_diferencias=0.0;
  double sumatoria_gral=0.0;
  float varianza=0.0;
  float desviacion=0.0;

  llenar_vec(vec);  /*Se llena el arreglo principal*/

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango);

  div_conjunto = 100000/p;


    if (mi_rango != 0) { /* -- Esclavos -- fuentes encargadas de realizar los calculos */
        sub_vec = (int*)malloc(div_conjunto * sizeof(int));
        MPI_Recv(sub_vec, div_conjunto, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); /* Se recibe un sub vector para luego calcular el sub promedio*/
        sub_prom=obtener_sub_prom(div_conjunto,sub_vec);
        printf("Sub promedio ESCLAVO %d : %.4f\n",mi_rango, sub_prom );
        MPI_Send(&sub_prom, 2 , MPI_FLOAT, 0, tag, MPI_COMM_WORLD); /*Se envia el el sub promedio a MASTER*/

        MPI_Recv(&prom, 2, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); /* Se recibe el promedio general */

        sumatoria_diferencias=obtener_dif_cuadrada(prom,div_conjunto,sub_vec); /* Se obtiene la sub sumatoria de las diferencias al cuadrado del sub vector*/
        printf("Sub sumatoria de diferencias al cuadrado Esclavo %d : %.4f\n",mi_rango, sumatoria_diferencias );
        MPI_Send(&sumatoria_diferencias, 2 , MPI_FLOAT, 0, tag, MPI_COMM_WORLD); /*Se envia la sub sumatoria a MASTER*/


    } else {    /* -- MASTER -- fuente encargada de distribuir los sub vectores*/
        for (int fuente = 1; fuente < p; fuente++) {
            sub_vec = create_sub_vec(fuente*div_conjunto, (fuente*div_conjunto)+div_conjunto, vec); /*Creación de sub vectores*/
            MPI_Send(sub_vec, div_conjunto, MPI_INT, fuente, tag, MPI_COMM_WORLD); /* Envía sub vectores a todas las fuentes (exceptuando MASTER)*/
        }

        sub_vec = create_sub_vec(0, div_conjunto, vec);   /* Sub vector en MASTER */

        for (int fuente = 1; fuente < p; fuente++) {
            MPI_Recv(&sub_prom, 2, MPI_FLOAT, fuente, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); /* Se recibe un sub vector por cada ESCLAVO, para luego calcular el promedio general*/
            prom=prom+sub_prom; /* Se agregan los promedios que van llegando*/
        }

        sub_prom=obtener_sub_prom(div_conjunto,sub_vec);  /* Sub promedio del vector */
        prom=prom+sub_prom;   /* Se comienza la sumatoria para el promedio general */
        printf("Sub promedio MASTER %d : %.4f\n",mi_rango, sub_prom );

        printf("#PROMEDIO GENERAL (MASTER %d) : %.4f\n",mi_rango, prom );

        for (int fuente = 1; fuente < p; fuente++) {
            MPI_Send(&prom, 2 , MPI_FLOAT, fuente, tag, MPI_COMM_WORLD);; /* Envía el promedio general a todas las fuentes (exceptuando MASTER)*/
        }

        for (int fuente = 1; fuente < p; fuente++) {
            MPI_Recv(&sumatoria_diferencias, 2, MPI_FLOAT, fuente, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); /* Se recibe una sub sumatoria por cada ESCLAVO, para luego calcular la varianza*/
            sumatoria_gral=sumatoria_gral+sumatoria_diferencias; /* Se agregan los promedios que van llegando*/
        }

        sumatoria_diferencias=obtener_dif_cuadrada(prom,div_conjunto,sub_vec); /* Se obtiene la sub diferencia al cuadrado de MASTER*/
        sumatoria_gral=sumatoria_gral+sumatoria_diferencias;
        printf("Sub sumatoria de diferencias al cuadrado MASTER %d : %.4f\n",mi_rango, sumatoria_diferencias );

        printf("Sumatoria General de diferencias al cuadrado (MASTER %d) : %.4f\n",mi_rango, sumatoria_gral );

        varianza=sumatoria_gral/100000.0;

        printf("#VARIANZA (MASTER %d) : %.4f\n",mi_rango, varianza );

        desviacion= desv(varianza);   /* Se calcula la desviacion estandar en base a la varianza */

        printf("#DESVIACION ESTANDAR (MASTER %d) : %.4f\n",mi_rango, desviacion );

        //print(mi_rango, p, div_conjunto, sub_vec);
    }



    MPI_Finalize();
    return 0;

}
