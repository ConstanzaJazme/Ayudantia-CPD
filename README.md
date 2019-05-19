# TAREA 5 - AYUDANTIA CPD

Descripción:*En base a tres ficheros xlsx (Docentes.xlsx / Salas.xlsx / Cursos.xlsx), se entrega la cantidad de filas de cada fichero, ademas se indica la cantidad de asignaturas de cada docente.*

Instalación:
  1. Instalar CMake.
    $ sudo apt-get install cmake
  
  2. Instalar Libreria.
    $ git clone https://github.com/tfussell/xlnt.git
    $ cd xlnt
    $ cmake .
    $ make -j 2
    $ sudo make install
    $ sudo ldconfig
  
  3. Compilar con:
    $ g++ main.cpp -o tarea -std=c++14 -xlnt/include -lxlnt
    
  4. Ejecutar con:
    $ ./tarea

Error de .so:
  Agregar "/usr/local/lib" al final de /etc/ld.so.conf
    $ sudo ldconfig
    $ ldconfig -p | grep local
    
    
    
# Tarea-2---Ayudantia-CPD

Algoritmo escrito en C++, el cual realiza 4 mètodos:

  1.-Llena un arreglo con 100.000 numeros aleatorios
  
  2.-Calcula su promedio
  
  3.-Calcula su varianza
  
  4.-Calcula su desviaciòn estandar
