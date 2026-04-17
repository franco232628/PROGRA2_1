//
// Created by GRINGO on 17/04/2026.
//

#include "AuxiliaryFunctions.hpp"


#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "faltas.hpp"

using namespace std;

#define INC 5
#define INC_PLACAS 2

// ================= UTIL =================

char *asignar_cadena(const char *buffer) {
    char *str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

char *read_str(ifstream &input, int max, char delim) {
    char buffer[max];
    input >> ws;
    if (!input.getline(buffer, max, delim)) return nullptr;
    return asignar_cadena(buffer);
}




char *copiar(const char *cad) {
    char *p = new char[strlen(cad)+1];
    strcpy(p, cad);
    return p;
}

// ================= RECORTE EXACTO =================
void recortarEnteros(int *&arr, int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) aux[i] = arr[i];
    delete[] arr;
    arr = aux;
}

void recortarCadenas(char **&arr, int n) {
    char **aux = new char*[n];
    for (int i = 0; i < n; i++) aux[i] = arr[i];
    delete[] arr;
    arr = aux;
}

void recortarDouble(double *&arr, int n) {
    double *aux = new double[n];
    for (int i = 0; i < n; i++) aux[i] = arr[i];
    delete[] arr;
    arr = aux;
}

// ================= CONDUCTORES =================
void operator+=(Conductores &c, const char *archivo) {
    //#define INC 5
// #define INC_PLACAS 2
    ifstream input(archivo);

    int cap = 0;
    c.cantidad = 0;
    c.dnis = nullptr;
    c.nombres = nullptr;

    int dni;
    while (input >> dni) {
        input.get();
        if (c.cantidad == cap) {
            cap += INC;

            int *auxDni = new int[cap];
            char **auxNom = new char*[cap];

            for (int i = 0; i < c.cantidad; i++) {
                auxDni[i] = c.dnis[i];
                auxNom[i] = c.nombres[i];
            }

            delete[] c.dnis;
            delete[] c.nombres;

            c.dnis = auxDni;
            c.nombres = auxNom;
        }

        c.dnis[c.cantidad] = dni;
        c.nombres[c.cantidad] = read_str(input, 50, '\n');
        c.cantidad++;
    }

    // 🔥 RECORTE EXACTO
    recortarEnteros(c.dnis, c.cantidad);
    recortarCadenas(c.nombres, c.cantidad);
}

// ================= INFRACCIONES =================
void operator+=(Infracciones &inf, const char *archivo) {

    ifstream input(archivo);
    /*f.conductores += "Datos/Conductores.csv";
    f.infracciones += "Datos/Infracciones.csv";

    int n = f.conductores.cantidad;

    f.placas = new char**[n]{};
    f.capacidades = new int[n]{};
    */

    int cap = 0;
    inf.cantidad = 0;

    inf.codigos = nullptr;
    inf.descripciones = nullptr;
    inf.tipos = nullptr;
    inf.valores = nullptr;

    int cod;

    while (input >> cod) {
        input.get();
        if (inf.cantidad == cap) {
            cap += INC;

            int *auxCod = new int[cap];
            char **auxDesc = new char*[cap];
            char **auxTipo = new char*[cap];
            double *auxVal = new double[cap];

            for (int i = 0; i < inf.cantidad; i++) {
                auxCod[i] = inf.codigos[i];
                auxDesc[i] = inf.descripciones[i];
                auxTipo[i] = inf.tipos[i];
                auxVal[i] = inf.valores[i];
            }

            delete[] inf.codigos;
            delete[] inf.descripciones;
            delete[] inf.tipos;
            delete[] inf.valores;

            inf.codigos = auxCod;
            inf.descripciones = auxDesc;
            inf.tipos = auxTipo;
            inf.valores = auxVal;
        }

        inf.codigos[inf.cantidad] = cod;
        inf.descripciones[inf.cantidad] = read_str(input, 210, ',');
        inf.tipos[inf.cantidad] = read_str(input, 20, ',');
        input >> inf.valores[inf.cantidad];
        input.get();
        inf.cantidad++;
    }

    // 🔥 RECORTE EXACTO
    recortarEnteros(inf.codigos, inf.cantidad);
    recortarCadenas(inf.descripciones, inf.cantidad);
    recortarCadenas(inf.tipos, inf.cantidad);
    recortarDouble(inf.valores, inf.cantidad);
}

// ================= AUX =================
int buscar(Conductores &c, int dni) {
    for (int i = 0; i < c.cantidad; i++)
        if (c.dnis[i] == dni) return i;
    return -1;
}

int contar(char **placas) {
    if (placas == nullptr) return 0;
    int i = 0;
    while (placas[i]) i++;
    return i;
}

bool existe(char **placas, const char *placa) {
    if (placas == nullptr) return false;
    for (int i = 0; placas[i]; i++)
        if (strcmp(placas[i], placa) == 0) return true;
    return false;
}/*
int pos = buscar(f.conductores, dni);
if (pos == -1) continue;
if (!existe(f.placas[pos], placa))
    insertar(f, pos, placa);
    }
}

void insertar(Faltas &f, int pos, const char *placa) {
    int usados = contar(f.placas[pos]);

    if (usados == f.capacidades[pos])
        incrementar(f.placas[pos], f.capacidades[pos], usados);

    f.placas[pos][usados] = copiar(placa);
    f.placas[pos][usados + 1] = nullptr;
}













*/

// ================= INCREMENTOS =================
void incrementar(char **&arr, int &cap, int usados) {
    char **aux;
    cap += INC_PLACAS;

    if (arr == nullptr) {
        arr = new char*[cap]{};
    } else {
        aux = new char*[cap]{};
        for (int i = 0; i < usados; i++)
            aux[i] = arr[i];

        delete[] arr;
        arr = aux;
    }
}

void insertar(Faltas &f, int pos, const char *placa) {
    int usados = contar(f.placas[pos]);

    if (usados == f.capacidades[pos])
        incrementar(f.placas[pos], f.capacidades[pos], usados);

    f.placas[pos][usados] = copiar(placa);
    f.placas[pos][usados + 1] = nullptr;
}

// ================= CARGA =================
void cargar_faltas(Faltas &f) {

    f.conductores += "Datos/Conductores.csv";
    f.infracciones += "Datos/Infracciones.csv";

    int n = f.conductores.cantidad;

    f.placas = new char**[n]{};
    f.capacidades = new int[n]{};

    ifstream input("Datos/Faltas.csv");

    int dni, cod;
    char placa[20], fecha[20];

    while (true) {
        input >> dni;
        if (input.eof()) break;
        input.get();
        input.getline(placa, 20, ',');
        input.getline(fecha, 20, ',');
        input >> cod;
        input.get();

        int pos = buscar(f.conductores, dni);
        if (pos == -1) continue;

        if (!existe(f.placas[pos], placa))
            insertar(f, pos, placa);
    }
}

// ================= REPORTE =================
void imprimir_reporte(const Faltas &f) {

    cout << "reporte\n";
    cout << "====================================================\n";
    cout << left << setw(12) << "DNI"
         << setw(35) << "CLIENTE"
         << setw(10) << "CANT VEHICULOS\n";
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < f.conductores.cantidad; i++) {
        int cant = contar(f.placas[i]);
        if (cant > 0) {
            cout << left << setw(12) << f.conductores.dnis[i]
                 << setw(40) << f.conductores.nombres[i]
                 << setw(10) << cant << endl;
        }
    }

    cout << "====================================================\n";
}