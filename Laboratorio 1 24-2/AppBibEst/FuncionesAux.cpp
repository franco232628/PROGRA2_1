//
// Created by renat on 29/3/2026.
//

#include "FuncionesAux.hpp"

void LeerPlatos(ifstream &archPlatos,Plato *platos) {
    int i=0;
    while (true) {
        archPlatos>>platos[i];
        if (archPlatos.eof()) break;
        i++;
    }
    strcpy(platos[i].codigo,"FIN");
}
void LeerRepartidores(ifstream &archRep,Repartidor *repartidores) {
    int i=0;
    while (true) {
        archRep>>repartidores[i];
        if (archRep.eof()) break;
        i++;
    }
    strcpy(repartidores[i].codigo,"FIN");
}
void LeerPedidos(ifstream &archPed,Pedido * pedidos) {
    int i=0;
    while (true) {
        archPed>>pedidos[i];
        if (archPed.eof()) break;
        i++;
    }
    pedidos[i].dniDelCliente=0;
}
void ActualizarPlatos(Plato *platos,Pedido *  pedidos) {
    int i=0;
    while (true) {
        if (pedidos[i].dniDelCliente==0) break;
        pedidos[i]<=platos;
        i++;
    }
}
void ActualizarRepartidores(Repartidor *repartidores,Pedido* pedidos) {
    int i=0;
    while (true) {
        if (pedidos[i].dniDelCliente==0) break;
        repartidores<=pedidos[i];
        i++;
    }
    i=0;
    while (true) {
        if (strcmp(repartidores[i].codigo,"FIN")==0) break;
        !repartidores[i];
        i++;
    }
}
void ImprimirReportePlatos(ofstream &reportePlatos,Plato * platos) {
    int i=0;
    while (true) {
        if (strcmp(platos[i].codigo,"FIN")==0) break;
        reportePlatos<<platos[i];
        i++;
    }
}
void ImprimirRepartidores(ofstream &reporteRepartidores,Repartidor * repartidores) {
    int i=0;
    while (true) {
        if (strcmp(repartidores[i].codigo,"FIN")==0) break;
        reporteRepartidores<<repartidores[i];
        i++;
    }
}