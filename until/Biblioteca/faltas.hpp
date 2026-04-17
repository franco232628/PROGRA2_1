//
// Created by GRINGO on 17/04/2026.
//

#ifndef UNTIL_FALTAS_HPP
#define UNTIL_FALTAS_HPP

#include <fstream>
using namespace std;

struct Conductores {
    int *dnis;
    char **nombres;
    int cantidad;
};

struct Infracciones {
    int *codigos;
    char **descripciones;
    char **tipos;
    double *valores;
    int cantidad;
};

struct Faltas {
    Conductores conductores;
    Infracciones infracciones;
    char ***placas;
    int *capacidades;
};

void operator+=(Conductores &c, const char *archivo);
void operator+=(Infracciones &inf, const char *archivo);

void cargar_faltas(Faltas &f);
void imprimir_reporte(const Faltas &f);


#endif //UNTIL_FALTAS_HPP