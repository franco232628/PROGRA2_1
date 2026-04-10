#ifndef INC_111_ESTATICA_LIBRARY_H
#define INC_111_ESTATICA_LIBRARY_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>


using namespace std;


#include  "Estructuras.h"


void operator>>(ifstream &input, Cursos &curso);
void operator>>(ifstream &input, Alumnos &alumno);

char * read_str( ifstream & input, int MAX, char delim);
double read_double( ifstream & input);
int read_int( ifstream & input);
char * asignar_cadena(char * buffer);

//operacion
bool operator>(struct Alumnos alumnos, int codigoAlumno);
bool operator>(struct Cursos cursos, char *codigoCurso);
void operator+=(struct Cursos &cursos,struct Alumnos &alumnos);
int operator<=(struct Alumnos *arrAlumnos, struct Alumnos alumno);
int operator>=(struct Cursos *arrCursos, struct Cursos cursos);

void operator++(struct Cursos &cursos);

//impreison
void operator<<(ofstream &output, struct Cursos &cursos);













#endif // INC_111_ESTATICA_LIBRARY_H