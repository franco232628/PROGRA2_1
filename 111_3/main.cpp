#include "FuncionesAuxiliares.hpp"



int main() {
    Alumnos arrAlumnos[80];
    cargarAlumnos("Datos/Alumnos.csv", arrAlumnos);

    // int i =0;
    // while (true) {
    //     if (arrAlumnos[i].codigo == 0) break;
    //     cout << arrAlumnos[i].codigo << " - " << arrAlumnos[i].nombre
    //             << " - " << arrAlumnos[i].tipo << endl;
    //     i++;
    // }

    Cursos arrCursos[10];
    cargarCursos(arrCursos, "Datos/Cursos.csv");
    int i = 0;
    while (true) {
        if (arrCursos[i].codigo == nullptr) break;
        cout << arrCursos[i].codigo << " - " << arrCursos[i].nombre
                << " - " << arrCursos[i].creditos << " - "<< arrCursos[i].docente
                << " - " << arrCursos[i].numpresencial << " - "<< arrCursos[i].numsemipresencial
                << " - " << arrCursos[i].numvirtual<< endl;
        i++;
    }
    cargarMatricula(arrAlumnos,arrCursos,"Datos/Matricula.csv");
    ActualizarCursos(arrCursos);
    cout << "nuevooo"<<endl;
    int j= 0;
    while (true) {
        if (arrCursos[j].codigo == nullptr) break;
        cout << arrCursos[j].codigo << " - " << arrCursos[j].nombre
                << " - " << arrCursos[j].creditos << " - "<< arrCursos[j].docente
                << " - " << arrCursos[j].numpresencial << " - "<< arrCursos[j].numsemipresencial
                << " - " << arrCursos[j].numvirtual<< endl;
        j++;
    }
    GenerarReporte(arrCursos, "Reporte/report.txt");
    return 0;
}
