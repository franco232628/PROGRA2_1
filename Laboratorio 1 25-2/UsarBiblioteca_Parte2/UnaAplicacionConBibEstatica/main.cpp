#include "FuncionesAuxiliares.hpp"

int main() {
    ifstream archAlumno("Alumnos.csv",ios::in);
    ifstream archCurso("Cursos.csv",ios::in);
    ifstream archMatricula("Matricula.csv",ios::in);
    ofstream reporte("reporte.txt",ios::out);
    Alumnos alumnos[80];
    Cursos cursos[10];
    CargarAlumnos(archAlumno, alumnos);
    CargarCursos(archCurso,cursos);
    CargarMatricula(archMatricula, alumnos, cursos);
    ActualizarCursos(cursos);
    GenerarReporte(reporte, cursos);
    return 0;
}