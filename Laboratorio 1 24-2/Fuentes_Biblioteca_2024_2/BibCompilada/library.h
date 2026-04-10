#ifndef BIBCOMPILADA_LIBRARY_H
#define BIBCOMPILADA_LIBRARY_H

#include  "Estructuras.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
void operator >> (ifstream &input, Plato &plato);
void operator >> (ifstream &input, Repartidor &repartidor);
void operator >>(ifstream &input, Pedido &pedido);
bool operator <=(Pedido &pedido, Plato *arregloPlatos);
void operator <= (Repartidor *arregloRepartidores, Pedido &pedido);
void operator !(OrdenDeCompra &ordenDeCompra);
void operator !(Repartidor &repartidor);
void operator <<(ofstream &reporte, Plato plato);
void operator <<(ofstream &reporte, Repartidor repartidor);
#endif // BIBCOMPILADA_LIBRARY_H