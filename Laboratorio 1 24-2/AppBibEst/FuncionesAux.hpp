//
// Created by renat on 29/3/2026.
//

#ifndef APPBIBEST_FUNCIONESAUX_HPP
#define APPBIBEST_FUNCIONESAUX_HPP
#include "library.h"
void LeerPlatos(ifstream &archPlatos,Plato *platos);
void LeerRepartidores(ifstream &archRep,Repartidor *repartidores);
void LeerPedidos(ifstream &archPed,Pedido * pedidos);
void ActualizarPlatos(Plato *platos,Pedido *  pedidos);
void ActualizarRepartidores(Repartidor *repartidores,Pedido* pedidos);
void ImprimirReportePlatos(ofstream &reportePlatos,Plato * platos);
void ImprimirRepartidores(ofstream &reporteRepartidores,Repartidor * repartidores);
#endif //APPBIBEST_FUNCIONESAUX_HPP