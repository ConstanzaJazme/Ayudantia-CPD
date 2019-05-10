CXX = mpic++
CXXFLAGS = -g3 -Wall
MKDIR = mkdir -p

LIBS=-lm -lmpi

directorios: 
	$(MKDIR) build dist

tarea3.o: directorios tarea3.cpp
	$(CXX) $(CXXFLAGS) -c tarea3.cpp -o build/tarea3.o

#utilidades.o: directorios utilidades.c utilidades.h
#	$(CXX) $(CXXFLAGS) -c utilidades.c -o build/utilidades.o

all: clean tarea3.o
	$(CXX) $(CXXFLAGS) $(LIBS) -o dist/programa build/tarea3.o
	rm -fr build

clean:
	rm -fr *.o a.out programa dist build

.DEFAULT_GOAL := all
