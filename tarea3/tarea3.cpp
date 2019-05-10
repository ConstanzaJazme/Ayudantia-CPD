/*
 *Programa que paraleliza funciones de: llenar arreglo, obtener promedio, varianza y desviación estandar
 *Autor: Constanza Jazme
 *Fecha: 11-05-2019
 *
 **/

#include<mpi.h>
#include<stdio.h>

/** Funcion para generar numeros aleatorios */

int aleatorio(){
        int random;
        random=1+rand()%501;
        return random;
}

/**Función para crear y llenar sub vectores*/

int* create_sub_vec(int begin, int end, int* origin){
    int* sub_vec;
    int size;
    int aux = 0;
    size = end - begin;
    sub_vec = (int*)malloc(size * sizeof(int));
    for (int i = begin; i < end; ++i) {
        *(sub_vec+aux) = aleatorio();
        aux += 1;
    }
    return  sub_vec;
}

/**Función para obtener el promedio de un subvector**/

float get_sub_prom(int begin, int end, int* sub_vec){ /* Se ingresa a la función: el inicio del sub_vec, el fin, el sub_vec y el vector con datos*/
  float sub_prom=0;  /* variable en donde se almacenará el promedio del sub vector*/
  int aux=0;    /* Espacios que avanzara en el arreglo*/
  float sum=0.0;    /* Suma de los elementos del vector*/

  for (int i = begin; i < end; ++i) {   /* Recorre desde posicion inicial a posición final del sub vector*/
      sum=sum+*(sub_vec+aux);   /* Obtiene valores almacenados en el sub vector  (Esto solo llega hasta end-begin-1)*/
      aux += 1;   /* Avanza un espacio*/
  }

  sub_prom=sum/(end-begin); /*Obtiene el sub promedio*/
  return sub_prom;

}


void print_all_prom(int p, float* all_prom){
   printf("#########################ESTO ES UNA PRUEBA####################\n");
    for (int i = 0; i < p; ++i)
    {
        printf("%f, ", *(all_prom+i));
    }
    printf("#############FIN PRUEBA################\n");
}

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
  int fuente; /* rango del que envia  */
  int dest; /* rango del que recibe */
  int tag = 0; /* etiqueta del mensaje */
  float sub_prom;

  int div_conjunto; /* n sobre p, indica en cuantos datos contiene un conjunto ideal (simetrico con los demás)*/
  int vec[100000]; /* Declaración del arreglo*/
  int* sub_vec = NULL;
  float info_clave[3];


  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango);


  div_conjunto = 100000/p;
//  sub_prom = (float*)malloc(size * sizeof(int));
  printf("Process %d calcula n_over_p = %d\n", mi_rango, div_conjunto);

    if (mi_rango != 0) {  /*En esta parte se tiene el arreglo con datos*/
        sub_vec = (int*)malloc(div_conjunto * sizeof(int));
        MPI_Recv(sub_vec, div_conjunto, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        print(mi_rango, p, div_conjunto, sub_vec);


    } else {    /* Se rellena el arreglo*/

        printf("Distribuindo dados\n");
        for (fuente = 1; fuente < p; fuente++) {
            sub_vec = create_sub_vec(fuente*div_conjunto, (fuente*div_conjunto)+div_conjunto, vec);
            sub_prom=get_sub_prom(fuente*div_conjunto, (fuente*div_conjunto)+div_conjunto, sub_vec);
            info_clave[0]=sub_vec;
            info_clave[1]=sub_prom;
            MPI_Send(sub_vec, div_conjunto, MPI_INT, fuente, tag, MPI_COMM_WORLD);
        }
        printf("Fim da distribuicao de dados\n");

        sub_vec = create_sub_vec(0, div_conjunto, vec); //llena el primer conjunto de datos
        sub_prom=get_sub_prom(0,div_conjunto, sub_vec);

        //print(mi_rango, p, div_conjunto, sub_vec);
    }

    MPI_Finalize();
    return 0;

}
