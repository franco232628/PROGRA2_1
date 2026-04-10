//
// Created by GRINGO on 9/04/2026.
//

#ifndef INC_111_3_FUNCIONESAUXILIARES_HPP
#define INC_111_3_FUNCIONESAUXILIARES_HPP

#include "library.h"
char *read_str1(ifstream &input, int MAX, char delim);
void open_read(ifstream &input, const char *file_name);

void cargarAlumnos(const char *file_name, Alumnos *alumnos);

void cargarCursos(Cursos *cursos, const char *file_name);

void cargarMatricula(Alumnos *alumnos,
                     Cursos *cursos, const char *file_name);
void ActualizarCursos(Cursos * cursos);
void GenerarReporte(Cursos * cursos, const char * file_name);
void open_print( ofstream & output, const char * file_name);


#endif //INC_111_3_FUNCIONESAUXILIARES_HPP
