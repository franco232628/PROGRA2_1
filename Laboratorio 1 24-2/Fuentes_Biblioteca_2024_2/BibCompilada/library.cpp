#include "library.h"


//AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
void operator >> (ifstream &input, Plato &plato) {
    input.getline(plato.codigo,7,',');
    input.getline(plato.nombre,60,',');
    input>>plato.precio;
    input.get();
    input.ignore(20,'\n');
    plato.totalDePedidos=0;
    plato.totalRecaudado=0.0;
}
//JNV387,Justino Norabuena Virginia Karina,Motocicleta
void operator >> (ifstream &input, Repartidor &repartidor) {
    input.getline(repartidor.codigo,7,',');
    input.getline(repartidor.nombre,60,',');
    input.getline(repartidor.tipoDeVehiculo,15,'\n');
    repartidor.pagoPorEntregas=0.0;
    for (int i=0;i<10;i++) {
        repartidor.ordenesDeCompra[i].cantidadDePlatos=0;
        repartidor.ordenesDeCompra[i].distancia=0.0;
        repartidor.ordenesDeCompra[i].montoPorCobrar=0.0;
        repartidor.ordenesDeCompra[i].pagoPorEnvio=0.0;
        for (int j=0;j<10;j++) {
            repartidor.ordenesDeCompra[i].platosSolicitados[j].cantidad=0;
        }
    }
}
//15290194  BR-283    1    MCE193    11.69
void operator >>(ifstream &input, Pedido &pedido) {
    input>>pedido.dniDelCliente>>ws;
    input.getline(pedido.codigoDelPlato, 7,' ');
    input>>pedido.cantidad>>ws;
    input.getline(pedido.codigoDelRepartidor,7,' ');
    input>>pedido.distanciaARecorrer;
    input.get();
}

bool operator <=(Pedido &pedido, Plato *arregloPlatos) {
    int i=0;
    while (true) {
        if (strcmp(arregloPlatos[i].codigo,"FIN")==0) break;
        if (strcmp(pedido.codigoDelPlato, arregloPlatos[i].codigo)==0) {
            pedido.precio = arregloPlatos[i].precio;
            arregloPlatos[i].totalDePedidos+=pedido.cantidad;
            return true;
        }
        i++;
    }
    return false;
}

void operator <= (Repartidor *arregloRepartidores, Pedido &pedido) {
    int i=0;
    while (true) {
        if (strcmp(arregloRepartidores[i].codigo,"FIN")==0) break;
        if (strcmp(arregloRepartidores[i].codigo,pedido.codigoDelRepartidor)==0) {
            int indice_cliente=-1,cant_ordenes = arregloRepartidores[i].cantidadDeOrdenes;
            for (int j=0;j<cant_ordenes;j++) {
                if (arregloRepartidores[i].ordenesDeCompra[j].dniDelCliente==pedido.dniDelCliente) {
                    indice_cliente=j;
                }
            }
            if (indice_cliente==-1) {
                indice_cliente=cant_ordenes;
                arregloRepartidores[i].cantidadDeOrdenes++;
            }
            int indice_plato=-1,cant_platos=arregloRepartidores[i].ordenesDeCompra[indice_cliente].cantidadDePlatos;

            for (int j=0;j<cant_platos;j++) {
                if (strcmp(arregloRepartidores[i].ordenesDeCompra[indice_cliente].platosSolicitados[j].codigo,pedido.codigoDelPlato)==0) {
                    indice_plato=j;
                }
            }
            if (indice_plato==-1) {
                indice_plato=cant_platos;
                arregloRepartidores[i].ordenesDeCompra[indice_cliente].cantidadDePlatos++;
                arregloRepartidores[i].ordenesDeCompra[indice_cliente].distancia+=pedido.distanciaARecorrer;

            }
            arregloRepartidores[i].ordenesDeCompra[indice_cliente].dniDelCliente=pedido.dniDelCliente;
            arregloRepartidores[i].ordenesDeCompra[indice_cliente].platosSolicitados[indice_plato].cantidad+=pedido.cantidad;
            arregloRepartidores[i].ordenesDeCompra[indice_cliente].platosSolicitados[indice_plato].precio+=pedido.precio;
            strcpy(arregloRepartidores[i].ordenesDeCompra[indice_cliente].platosSolicitados[indice_plato].codigo,pedido.codigoDelPlato);

        }

        i++;
    }
}

void operator !(OrdenDeCompra &ordenDeCompra) {
    double dist=ordenDeCompra.distancia;
    if (dist<8) ordenDeCompra.pagoPorEnvio=8;
    else if (dist<12) ordenDeCompra.pagoPorEnvio=14.8;
    else if (dist<20) ordenDeCompra.pagoPorEnvio=23.6;
    else ordenDeCompra.pagoPorEnvio=31.7;
    for (int i=0;i<ordenDeCompra.cantidadDePlatos;i++) {
        ordenDeCompra.montoPorCobrar+=(ordenDeCompra.platosSolicitados[i].cantidad * ordenDeCompra.platosSolicitados[i].precio);
    }
    ordenDeCompra.montoPorCobrar+=ordenDeCompra.pagoPorEnvio;

}

void operator !(Repartidor &repartidor) {
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        !repartidor.ordenesDeCompra[i];
        repartidor.pagoPorEntregas+=repartidor.ordenesDeCompra[i].montoPorCobrar;
    }
}

void operator <<(ofstream &reporte, Plato plato) {
    reporte<<plato.codigo<<"  "<<plato.nombre<<setw(60-strlen(plato.nombre))<<" "
    <<setw(6)<<plato.precio<<setw(7)<<plato.totalDePedidos<<setw(10)<<(plato.totalDePedidos*plato.precio)<<endl;

}

void operator <<(ofstream &reporte, Repartidor repartidor) {
    reporte<<repartidor.codigo<<setw(5)<<" "<<repartidor.nombre<<setw(60-strlen(repartidor.nombre))<<" "
    <<" "<<repartidor.tipoDeVehiculo<<setw(25-strlen(repartidor.tipoDeVehiculo))<<repartidor.pagoPorEntregas<<endl;
    reporte<<"ORDENES ENTREGADAS:"<<endl;
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        reporte<<setw(5)<<" "<<repartidor.ordenesDeCompra[i].dniDelCliente<<setw(10)<<repartidor.ordenesDeCompra[i].distancia
        <<setw(10)<<repartidor.ordenesDeCompra[i].montoPorCobrar<<setw(10)<<repartidor.ordenesDeCompra[i].pagoPorEnvio<<endl;
        reporte<<setw(5)<<" "<<"Platos solicitados:"<<endl;
        for (int j=0;j<repartidor.ordenesDeCompra[i].cantidadDePlatos;j++) {
            reporte<<setw(5)<<" - "<<repartidor.ordenesDeCompra[i].platosSolicitados[j].codigo
            <<setw(10)<<repartidor.ordenesDeCompra[i].platosSolicitados[j].precio<<setw(10)
            <<repartidor.ordenesDeCompra[i].platosSolicitados[j].cantidad<<setw(10)
            <<(repartidor.ordenesDeCompra[i].platosSolicitados[j].precio*repartidor.ordenesDeCompra[i].platosSolicitados[j].cantidad)
            <<endl;
        }
    }
}