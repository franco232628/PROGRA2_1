//
// Created by renat on 5/4/2026.
//

#ifndef UNAAPLICACIONCONBIBESTATICA_FUNCIONESAUXILIARES_HPP
#define UNAAPLICACIONCONBIBESTATICA_FUNCIONESAUXILIARES_HPP
#include  "library.h"
void CargarAlumnos(ifstream &archAlumno,Alumnos *alumnos);
void CargarCursos(ifstream &archCurso,Cursos *cursos);
void CargarMatricula(ifstream &archMatricula,Alumnos *alumnos,Cursos* cursos);
void ActualizarCursos(Cursos *cursos);
void GenerarReporte(ofstream &reporte,Cursos *cursos);
#endif //UNAAPLICACIONCONBIBESTATICA_FUNCIONESAUXILIARES_HPP