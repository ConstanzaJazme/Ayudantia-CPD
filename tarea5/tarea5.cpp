#include <iostream>
#include <stdlib.h>

using namespace std;

struct docente{
    int id_docente;
    char nombre[100];
    char apellido[100];
};

struct asignaturas{
    int id_curso;
    char nombre[100];
    int id_docente;
};

/* void llenar_docente(){
}*/

/* void llenar_asignaturas(){

}*/

/* Verifica que la cantidad de argumentos ingresados coincida con la cantidad requerida */
int verificar_argc(int argc, int cantidad){
    int cantidad_argc = argc - 1;

    /* Si la cantidad de argumentos es igual a la cantidad requerida, retorna un 1 */
    if (cantidad_argc = cantidad){
        return 1;
    }
    else /* En caso contrario retorna un 0 */
    {
        return 0;
    }
}

int main(int argc, char *argv[]){

    return 0;

}
