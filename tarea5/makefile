#Variables

CXX = g++
CXXFLAGS = -std=c++14

FUENTE = fabian.cpp
CABECERA = funciones.cpp
NOMBRE = tarea5
XLSX = Cursos.xlsx Docentes.xlsx Salas.xlsx

LIB = -Ixlnt/include -lxlnt


#Reglas


tarea: fabian.cpp
	$(CXX) $(FUENTE) $(CABECERA) -o $(NOMBRE) $(CXXFLAGS) $(LIB)
	clear
	./$(NOMBRE) $(XLSX)

ejecutar:
	clear
	./$(NOMBRE) $(XLSX)

clean:
	rm -fr *.o a.out $(NOMBRE)


