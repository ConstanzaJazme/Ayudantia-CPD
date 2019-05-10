/**
 * Tarea 2 de Ayudantìa Computaciòn Paralela y Distribuida
 *
 * Autor: Constanza Jazme Herrera
 *
 * Fecha: 28 de abril del 2019
 */
#include<iostream>
#include<math.h>

using namespace std;

/** Funcion para llenar arreglo con 100.000*/

void llenar(int arreglo[]){
        int random;
	srand(time(NULL));
        for (int i=0; i<100000; i++){
                random=1+rand()%501;
                arreglo[i]=random;
        }

}


/**Funcion para mostrar valores del  arreglo*/

void mostrar(int arreglo[]){ 
        for(int i=0;i<100000;i++){ 
                cout<<"Nº"<<i+1<<"= "<<arreglo[i]<<endl;
        }
	cout<<endl;
}


/**Funcion para calcular promedio*/

float prom(int arreglo[]){
	int sum=0;
	for(int i=0; i<100000;i++){
		sum=sum+arreglo[i];
	}
	return (sum/100000.0);
}

/**Funcion para calcular varianza */

float var(int arreglo[], float p){
	int sum=0;
	float num=0;
	for (int i=0;i<100000;i++){
		num=arreglo[i]-p;
		sum=sum+(num*num);
	}
	return (sum/100000.0);
}

/**Funcion para calcular desviacion estandar*/

float desv(float v){
	float  d=sqrt(v);
	return d;
}

int main(){
        int val[100000];
	float promedio,varianza,desviacion;
        llenar(val);
        mostrar(val);
	promedio=prom(val);
	varianza=var(val,promedio);
	desviacion=desv(varianza);
	cout<<"Este es el promedio: "<<promedio<<endl;
	cout<<"Esta es la varianza: "<<varianza<<endl;
	cout<<"Esta es la desviaciòn estandar: "<<desviacion<<endl;
        return 1;

}



