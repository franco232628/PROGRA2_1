//
// Created by renat on 29/3/2026.
//

#include "Funciones.hpp"
void  leerDatos(int *dni, struct CadenaDeCaracteres *conductor,
    struct  CadenaDeCaracteres *placa,ifstream & input,int &n) {
    CadenaDeCaracteres cadena;
    int i=0,ignorar;
    char guionbajo[2]="_";
    while (true) {
        input>>dni[i];
        if (input.eof()) break;
        bool primeraletra=true;
        //Se inicializa para poner las cadenas en nullptr y evitar errores
        !conductor[i];
        !placa[i];
        while (true) {
            !cadena;
            input>>ws;
            if ((input>>cadena)==-1) {
                break;
            }
            if (!primeraletra) conductor[i] +=guionbajo;
            if (!(conductor[i]+=cadena)) {
                conductor[i]<=cadena;
            }
            primeraletra=false;
        }
        input>>ignorar>>ws;
        input>>placa[i];
        i++;
    }
    n=i;
}
void ImprimirLinea(ofstream &reporte, char caracter) {
    for (int i=0;i<=70;i++) reporte<<caracter;
    reporte<<endl;
}
void ImprimirReporte(int *dni, struct CadenaDeCaracteres *conductor,
    struct  CadenaDeCaracteres *placa,ofstream &reporte, int n) {
    reporte<<setw(25)<<" "<<"REPORTE DE INFRACTORES DE TRANSITO"<<endl;
    ImprimirLinea(reporte,'=');
    reporte<<"DNI"<<setw(10)<<" "<<"INFRACTOR"<<setw(40)<<" "<<"PLACA"<<endl;
    ImprimirLinea(reporte,'-');
    for (int i=0;i<n;i++) {
        reporte<<dni[i]<<setw(5)<<" ";
        reporte<<conductor[i];
        reporte<<setw(49-conductor[i].longitud)<<" ";
        reporte<<placa[i];
        reporte<<endl;
    }
}
void Ordenamiento(int *dni, struct CadenaDeCaracteres *conductor,
    struct  CadenaDeCaracteres *placa, int n) {
    for (int i=n-1;i>0;i--) {
        for (int j=0;j<=i-1;j++) {
            if (conductor[j]>conductor[j+1]) {
                conductor[j]&&conductor[j+1];
                placa[j+1]&&placa[j];
                int aux = dni[j];
                dni[j]=dni[j+1];
                dni[j+1]=aux;
            }
        }
    }
}

