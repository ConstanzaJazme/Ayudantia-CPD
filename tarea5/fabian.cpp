#include <iostream>
#include <xlnt/xlnt.hpp>
#include <vector>
#include <typeinfo>

using namespace std;
using namespace xlnt;

//Cuenta la cantidad de filas que hay los archivos mandados por argumento.
void cantidadFilasPorArchivo(int argc, char *argv[]){
    if(argc > 1){ //Verifica la cantidad de argumentos a momento de ejecutar
      cout << "Cantidad de archivos ingresados: " << argc-1 << endl << endl;
      for(int archivos = 1; archivos < argc; archivos++){ //iteracion desde el el 2° objeto (1° es nombre del .cpp)
        cout << "Nombre archivo: " << argv[archivos] << endl;

        workbook xlsCursos; //instancia de objeto que aloja el xlsx
        xlsCursos.load(argv[archivos]); //carga del xlsx
        auto sheetCursos = xlsCursos.active_sheet(); //trabajando con la 1° pestaña del archivo

        int contadorFilas = 0;
        for (auto row : sheetCursos.rows(false)) //seudoForEach que recorrelas filas.
        {
          contadorFilas++;
        }

        cout << "Cantidad de filas: " << contadorFilas << endl << endl;
      }
    } else {
      cout << "No se ingresaron archivos .xlsx" << endl;
    }
}


//Muestra por pantalla el contenido de las primeras N filas de un vector bidimensional (Filas/Columnas)
void imprimirVectorNPrimeros(vector<vector<string>> vector, int nPrimeros){
    for (int fila = 1; fila <= nPrimeros; fila++) //Itera por fila hasta N
    {
      cout << "| ";
        for (int columna = 0; columna < vector.at(fila).size(); columna++) //itera por columna
        {
            cout << vector.at(fila).at(columna) << " | "; //Imprime lo que esta en la fila y columna indicada
        }
        cout << endl;
    }
}

//Muestra por pantalla una lista de los profesores desde un vector
void imprimeProfesores(vector<vector<string>> profes){
    for (int fila = 1; fila < profes.size(); fila++) //Itera por fila
    {
        cout << fila << ".- ";
        for (int columna = 0; columna < 3; columna++) //itera por columna
        {
            cout << profes.at(fila).at(columna) << " "; //Imprime lo que esta en la fila y columna indicada
        }
        cout << endl;
    }
}

//Cuenta la cantidad de asignarutas de cada profesor y las muestra por pantalla
void cantidadAsignaturasPorProfesor(int argc, char *argv[]){
    workbook xlsCursos;
    xlsCursos.load(argv[1]);
    auto sheetCursos = xlsCursos.active_sheet();

    workbook xlsDocentes;
    xlsDocentes.load(argv[2]);
    auto sheetDocentes = xlsDocentes.active_sheet();

    vector< vector<string> > vectorCursos;
    vector< vector<string> > vectorDocentes;

    for (auto row : sheetCursos.rows(false))
    {
        vector<string> filaCursos;
        for (auto cell : row)
        {
            filaCursos.push_back(cell.to_string());
        }
        vectorCursos.push_back(filaCursos);
    }

    for (auto row : sheetDocentes.rows(false))
    {
        vector<string> filaDocentes;
        for (auto cell : row)
        {
            filaDocentes.push_back(cell.to_string());
        }
        vectorDocentes.push_back(filaDocentes);
    }


    for (int profesores = 1; profesores < vectorDocentes.size(); profesores++)
    {
        int contadorAsignaturasPorProfesor = 0;
        for (int asignaturas = 1; asignaturas < vectorCursos.size(); asignaturas++){
            if(vectorCursos.at(asignaturas).at(2) == vectorDocentes.at(profesores).at(0)){
                contadorAsignaturasPorProfesor++;
            }
        }
        cout << profesores << ".- " << vectorDocentes.at(profesores).at(1) << " " << vectorDocentes.at(profesores).at(2) << " tiene: " << contadorAsignaturasPorProfesor << " asignaturas." << endl;
    }

}

void cargarArchivos(int argc, char *argv[]){
  
}

int main(int argc, char *argv[])
{
    cantidadFilasPorArchivo(argc, argv);
    cantidadAsignaturasPorProfesor(argc, argv);

    return 0;
}


// for (auto cell : row)
// {
//     cout << cell.to_string() << endl;
// }
