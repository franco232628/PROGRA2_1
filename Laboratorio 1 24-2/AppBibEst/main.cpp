#include "FuncionesAux.hpp"
int main() {
    ifstream archPlatos("PlatosOfrecidos.csv",ios::in),
    archRep("RepartidoresContratados.csv",ios::in),
    archPed("OrdenesDeCompra.txt",ios::in);
    ofstream reportePlatos("ReportePlatos.txt",ios::out),
    reporteRepartidores("ReporteRepartidores.txt",ios::out);
    Pedido pedidos[200];
    Plato platos[120];
    Repartidor repartidores[40];
    LeerPlatos(archPlatos,platos);
    LeerRepartidores(archRep,repartidores);
    LeerPedidos(archPed, pedidos);
    ActualizarPlatos(platos,  pedidos);

    ActualizarRepartidores(repartidores, pedidos);
    ImprimirReportePlatos(reportePlatos, platos);
    ImprimirRepartidores(reporteRepartidores, repartidores);
    return 0;
}