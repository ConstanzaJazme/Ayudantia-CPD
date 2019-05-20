# TAREA 5 - AYUDANTIA CPD

Descripción:*En base a tres ficheros xlsx (Docentes.xlsx / Salas.xlsx / Cursos.xlsx), se entrega la cantidad de filas de cada fichero, ademas se indica la cantidad de asignaturas de cada docente.*

## Instalación (Ubuntu):
1. Instalar CMake.
```
$ sudo apt-get install cmake
```
2. Instalar Libreria.

```
$ git clone https://github.com/tfussell/xlnt.git
$ cd xlnt
$ cmake .
$ make -j 2
$ sudo make install
$ sudo ldconfig
```

3. Compilar y Ejecutar con:
```
$ make
```

#### En el caso de errores:

- Si 'Make' no funciona, compilar y ejecutar con:
```
$ g++ main.cpp -o tarea -std=c++14 -xlnt/include -lxlnt
$ ./tarea Cursos.xlsx Docentes.xlsx Salas.xlsx
```
- Errores con archivo .so:

	Agregar "/usr/local/lib" al final de /etc/ld.so.conf y luego:
```
$ sudo ldconfig
$ ldconfig -p | grep local
```

## Objetivo de la tarea

Como tarea 5 se les pedirá  realizar un algoritmo escrito en C/C++ (lo que le acomode  más), que realicen ojala en métodos o funciones, de manera secuencial.

- Leer ficheros en xlsx del proyecto semestral.
- Debe contar las columnas de cada fichero. (ejemplo cursos.xlsx largo = 346)
- Indicar cuantas asignaturas tiene cada docente. (ejemplo S. Salazar = 1)


La tarea se debe realizar en grupo de 3 personas, se revisará la participación de cada integrante a través de su colaboración en GIT, de no tener una participación coherente 1.0.

La fecha de entrega es el día Lunes 20 de mayo a las 13:15 horas.

pd: debe ingresar los ficheros por ARGUMENTOS.
Ejemplo :
```
./ejecutable -s salas.xlsx -d docentes.xlsx -c cursos.xlsx
```
pd2: De no existir un fichero dar por finalizado el algoritmo.
