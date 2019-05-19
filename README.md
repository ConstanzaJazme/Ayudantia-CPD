# TAREA 5 - AYUDANTIA CPD

Descripción:*En base a tres ficheros xlsx (Docentes.xlsx / Salas.xlsx / Cursos.xlsx), se entrega la cantidad de filas de cada fichero, ademas se indica la cantidad de asignaturas de cada docente.*

Instalación:
  1. Instalar CMake.
    $ sudo apt-get install cmake
  
  2. Instalar Libreria.
    1. $ git clone https://github.com/tfussell/xlnt.git
    2. $ cd xlnt
    3. $ cmake .
    4. $ make -j 2
    5. $ sudo make install
    6. $ sudo ldconfig
  
  3. Compilar con:
    7. $ g++ main.cpp -o tarea -std=c++14 -xlnt/include -lxlnt
    
  4. Ejecutar con:
    8. $ ./tarea

Error de .so:
  1. Agregar "/usr/local/lib" al final de /etc/ld.so.conf
    1. $ sudo ldconfig
    2. $ ldconfig -p | grep local
    
    
    
# Tarea-2---Ayudantia-CPD

Algoritmo escrito en C++, el cual realiza 4 mètodos:

  1.-Llena un arreglo con 100.000 numeros aleatorios
  
  2.-Calcula su promedio
  
  3.-Calcula su varianza
  
  4.-Calcula su desviaciòn estandar
