//
// Created by GRINGO on 9/04/2026.
//

#include "FuncionesAuxiliares.hpp"

void open_read(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error opening file!" << file_name << endl;
        exit(1);
    }
}


void open_print(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error opening file!" << file_name << endl;
        exit(1);
    }
}

void cargarAlumnos(const char *file_name, Alumnos *alumnos) {
    ifstream input;
    open_read(input, file_name);
    //202111260,GORDILLO/CASTRO/RONAL,P
    int i = 0;
    while (true) {
        input >> alumnos[i];
        if (input.eof()) break;

        i++;
    }
    alumnos[i].codigo = 0;
}

void cargarCursos(Cursos *cursos, const char *file_name) {
    ifstream input;
    open_read(input, file_name);

    int i = 0;
    while (true) {
        input >> cursos[i];
        if (cursos[i].codigo == nullptr)break;
        i++;
    }
    cursos[i].codigo = nullptr;
}

void cargarMatricula(Alumnos *alumnos,
                     Cursos *cursos,
                     const char *file_name) {
    ifstream input;
    open_read(input, file_name);

    Alumnos alumno;
    int indice_alumno, indice_curso;

    while (true) {
        // INF263,202318320
        Cursos curso;
        curso.codigo = read_str1(input, 10, ',');
        if (curso.codigo == nullptr) break;
        // cout << endl<<curso.codigo;
        input >> alumno.codigo;
        // cout << endl << alumno.codigo;
        input.get();
        indice_alumno = (alumnos<=alumno);
        indice_curso = (cursos>=curso);
        if (indice_alumno != -1 && indice_curso != -1) {
            cursos[indice_curso] += alumnos[indice_alumno];
        }
    }
}
char *read_str1(ifstream &input, int MAX, char delim) {
    char *str, buffer[MAX];
    input >> ws;
    input.getline(buffer, MAX, delim);
    if (input.eof()) return nullptr;
    str = new char[strlen(buffer) + 1]{};
    strcpy(str, buffer);
    return str;
}


void ActualizarCursos(Cursos *cursos) {
        int i=0;
    while (true) {
        if (cursos[i].codigo == nullptr) break;
        ++cursos[i];
        i++;
    }
}



void GenerarReporte(Cursos *cursos, const char *file_name) {
    ofstream output;
    open_print(output, file_name);
    int i=0;
    while (true) {
        if (cursos[i].codigo ==nullptr) break;
        output << cursos[i];
        i++;
    }

}
