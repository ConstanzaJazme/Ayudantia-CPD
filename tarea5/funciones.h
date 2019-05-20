#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <xlnt/xlnt.hpp>
#include <vector>
#include <typeinfo>


using namespace std;
using namespace xlnt;

bool argumento_correcto(int  , char *[]); /*Funcion que valida si los argumento ingresados  se encuentran*/
int cantidadFilasPorArchivo(int , char *[]); //Cuenta la cantidad de filas que hay los archivos mandados por argumento.
void imprimirVectorNPrimeros(vector<vector<string>>, int ); //Muestra por pantalla el contenido de las primeras N filas
void imprimeProfesores(vector<vector<string>> );//Muestra por pantalla una lista de los profesores desde un vector
void cantidadAsignaturasPorProfesor(int , char *[]);//Cuenta la cantidad de asignarutas de cada profesor y las muestra por pantalla
void validarArgumentos(int, char *[]);/* Funcion que permite validar el ingreso correcto de los argumentos */


#endif // FUNCIONES_H_INCLUDED
