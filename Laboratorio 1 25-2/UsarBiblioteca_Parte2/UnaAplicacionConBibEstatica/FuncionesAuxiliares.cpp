//
// Created by renat on 5/4/2026.
//

#include "FuncionesAuxiliares.hpp"

void CargarAlumnos(ifstream &archAlumno,Alumnos *alumnos) {
    int i=0;
    while (true) {
        archAlumno>>alumnos[i];
        if (archAlumno.eof()) break;
        i++;
    }
    alumnos[i].codigo=0;
}
void CargarCursos(ifstream &archCurso,Cursos *cursos) {
    int i=0;
    while (true) {
        archCurso>>cursos[i];
        if (archCurso.eof()) break;
        i++;
    }
    cursos[i].codigo=nullptr;
}
void CargarMatricula(ifstream &archMatricula,Alumnos *alumnos,Cursos* cursos) {
    Alumnos alumno;
    int indice_alumno, indice_cursos;
    while (true) {
        Cursos curso;
        curso.codigo = LeerConDelimitador(archMatricula,',');
        if (archMatricula.eof()) break;
        archMatricula>>alumno.codigo;
        archMatricula.get();
        indice_alumno = (alumnos<=alumno);
        indice_cursos = (cursos>=curso);
        cursos[indice_cursos]+=alumnos[indice_alumno];
    }
}
void ActualizarCursos(Cursos *cursos) {
    int i=0;
    while (true) {
        if (cursos[i].codigo==nullptr) break;
        ++cursos[i];
        i++;
    }
}
void GenerarReporte(ofstream &reporte,Cursos *cursos) {
    int i=0;
    while (true) {
        if (cursos[i].codigo==nullptr) break;
        reporte<<cursos[i];
        i++;
    }
}