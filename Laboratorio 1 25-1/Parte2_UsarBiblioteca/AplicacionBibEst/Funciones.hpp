//
// Created by renat on 29/3/2026.
//

#ifndef APLICACIONBIBEST_FUNCIONES_HPP
#define APLICACIONBIBEST_FUNCIONES_HPP
#include "library.h"
void  leerDatos(int *dni, struct CadenaDeCaracteres *conductor,
    struct  CadenaDeCaracteres *placa,ifstream & input,int &n);
void ImprimirLinea(ofstream &reporte, char caracter);
void ImprimirReporte(int *dni, struct CadenaDeCaracteres *conductor,
    struct  CadenaDeCaracteres *placa,ofstream &reporte, int n);
void Ordenamiento(int *dni, struct CadenaDeCaracteres *conductor,
    struct  CadenaDeCaracteres *placa, int n);
#endif //APLICACIONBIBEST_FUNCIONES_HPP