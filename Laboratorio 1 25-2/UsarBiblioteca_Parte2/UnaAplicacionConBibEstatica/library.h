#ifndef FUENTES_BIBLIOTECA_LIBRARY_H
#define FUENTES_BIBLIOTECA_LIBRARY_H
#include "Estructuras.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
char *LeerConDelimitador(ifstream &input, char delimitador);
void operator >> (ifstream &input, Cursos &curso);
void operator >> (ifstream &input, Alumnos &alumno);
bool operator > (struct Alumnos alumnos, int codigoalumno);
bool operator > (struct Cursos cursos, char *codigo);
void operator +=(struct Cursos &curso, struct Alumnos &alumno);
int operator <=(struct Alumnos *arrAlumnos, struct Alumnos alumno);
int operator >=(struct Cursos *arrCursos, struct Cursos curso);
void operator ++(struct Cursos &curso);
void operator <<(ofstream &output, struct Cursos &cursos);
#endif // FUENTES_BIBLIOTECA_LIBRARY_H