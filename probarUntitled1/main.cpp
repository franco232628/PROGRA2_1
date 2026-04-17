#include "Biblioteca/Mylibreria.hpp"


int main() {
    ifstream archMascotas("ArchivosDeDatos/Mascotas.csv");
    ifstream archVeterinario("ArchivosDeDatos/Veterinarios.csv");
    ifstream archAtencion("ArchivosDeDatos/Atenciones.csv");

    ofstream archReporte("ArchivosDeReporte/Reporte.txt");
    ofstream archReporte1("ArchivosDeReporte/Reporte1.txt");
    ofstream archReporte2("ArchivosDeReporte/Reporte2.txt");
    ofstream archReporte3("ArchivosDeReporte/Reporte3.txt");

    Mascota m1,m2;
    Veterinario v1;
    Atencion at1, at2;

    /*
    ===================
        Lectura
    ================<
        */
    archMascotas >> m1;
    archMascotas >> m2;
    archVeterinario >> v1;
    archAtencion >> at1;
    archAtencion >> at2;

    cout << "Lectura correcctamente realizada" << endl;

    /*=============
        Prueba de impresion
        =================
        */
    archReporte << m1;
    archReporte1 << m2;
    archReporte2 << at1;
    archReporte3 << at2;
    //operaciones:

    Atencion at = at1;

    if (at == at1) {
        cout << "Atenciones iguales" << endl;
    }else
        cout << "Cometiste error" << endl;
    int fecha = 20240000;
    if (m1 <= fecha) {
        cout << "Lectura correcctamente" << endl;
        cout << m1.fechaNacimiento << " < " << fecha << endl;
    }
    else
        cout << "Cometiste error" << endl << m1.fechaNacimiento << " > " << fecha << endl;;

    return 0;
}
