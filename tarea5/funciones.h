#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <xlnt/xlnt.hpp>
#include <vector>
#include <typeinfo>


using namespace std;
using namespace xlnt;


void cantidadFilasPorArchivo(int , char *[]);
void imprimirVectorNPrimeros(vector<vector<string>>, int );
void imprimeProfesores(vector<vector<string>> );
void cantidadAsignaturasPorProfesor(int , char *[]);
void validarArgumentos(int, char *[]);


#endif // FUNCIONES_H_INCLUDED
