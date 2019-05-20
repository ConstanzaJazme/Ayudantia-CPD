#Variables

CXX = g++
CXXFLAGS = -std=c++14

FUENTE = fabian.cpp
NOMBRE = tarea
XLSX = Cursos.xlsx Docentes.xlsx Salas.xlsx

LIB = -Ixlnt/include -lxlnt


#Reglas


tarea: fabian.cpp
	$(CXX) $(FUENTE) -o $(NOMBRE) $(CXXFLAGS) $(LIB)
	clear
	./$(NOMBRE) $(XLSX)

ejecutar:
	clear
	./$(NOMBRE) $(XLSX)

clear:
	rm $(NOMBRE)
