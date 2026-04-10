#include "Funciones.hpp"


int main() {
    int *dni, cant_cond;
    struct CadenaDeCaracteres *conductor, *placa;
    ifstream input("Infracciones de transito.txt",ios::in);
    ofstream reporte("Reporte.txt",ios::out);
    dni = new int[120];
    conductor = new CadenaDeCaracteres[120];
    placa = new CadenaDeCaracteres[120];

    leerDatos(dni, conductor, placa, input, cant_cond);
    Ordenamiento(dni,conductor,placa,cant_cond);
    ImprimirReporte(dni,conductor,placa,reporte,cant_cond);

    return 0;
}