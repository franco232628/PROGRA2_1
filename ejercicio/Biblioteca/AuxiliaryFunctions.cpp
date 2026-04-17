//
// Created by HP on 16/04/2026.
//

#include "AuxiliaryFunctions.hpp"



void cargarDatos(const char *file_name1, const char *file_name2,
                 struct SistemaHuellitas &sistemahuellitas) {
    ifstream archMascota;
    open_read(archMascota, file_name1);
    ifstream archVeterinario;
    open_read(archVeterinario, file_name2);

    sistemahuellitas.numMascotas = 0;
    while (archMascota >> sistemahuellitas.mascotas[sistemahuellitas.numMascotas]) {
        sistemahuellitas.numMascotas++;
    }

    sistemahuellitas.numVeterinarios = 0;
    while ( archVeterinario >> sistemahuellitas.veterinario[sistemahuellitas.numVeterinarios]) {
        sistemahuellitas.numVeterinarios++;

    }
    sistemahuellitas.numAtencions = 0;
}

void open_read(ifstream &input, const char *file_name1) {
    input.open(file_name1, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

void open_print(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}



void registrarAtenciones(const char *file_name,
                         struct SistemaHuellitas &sistemaHuellitas) {
    ifstream input;
    open_read(input, file_name);
    int idCorrelativo = 1001;
    int cantRechazadas =0;

    Atencion atencionLeida;
    int k=0;
    while (input >> atencionLeida) {
        atencionLeida.idAtencion = idCorrelativo;
        idCorrelativo++;
        if (veterinarioOcupado(atencionLeida,sistemaHuellitas)) {
            int hora = atencionLeida.horayMinutos/3600;
            int minuto = (atencionLeida.horayMinutos/60)%60;
            cout << "Horario ocupado del veterinario ID: " << atencionLeida.idVeterinario<< " el "
            << atencionLeida.fecha<< " a las ";
            cout << hora << ':' << minuto << endl;
            cantRechazadas ++;
        }else {
            cout << "Entramos : " << k << endl;
            k++;
            sistemaHuellitas.atencion[sistemaHuellitas.numAtencions] = atencionLeida;
            sistemaHuellitas.numAtencions++;
        }

    }
    cout << cantRechazadas << " ATENCION(S) SIN PROGRAMAR" << endl;



}

bool veterinarioOcupado(Atencion atencion, struct SistemaHuellitas sistemaHuellitas) {
    for (int i = 0; i < sistemaHuellitas.numAtencions; i++) {
        if (sistemaHuellitas.atencion[i] == atencion) {
            return true;
        }
    }
    return false;
}



void imprimirListaMascotaAEsteriizar(const char *file_name, struct SistemaHuellitas sistemaHuellitas) {
    ofstream output;
    open_print(output, file_name);
    print_line(output, '=',35 );
    output << "*** MASCOTAS PARA ESTERILIZAAR ***" << endl;
    print_line(output, '=',35 );

    for (int i = 0; i < sistemaHuellitas.numMascotas; i++) {
        if (!(sistemaHuellitas.mascotas[i] <= 20251010)) {
            output << sistemaHuellitas.mascotas[i];
        }
    }
}

void print_line(ofstream &output, char carac, int MAX) {
    for (int i = 0; i < MAX; i++) output.put(carac);
    output.put('\n');
}

void imprimirTodo(const char *file_name, struct SistemaHuellitas sistemaHuellitas) {

    ofstream output;
    open_print(output, file_name);
    print_line(output, '=',30 );
    output << "*** MASCOTAS Y ATENCIONES ***" << endl;
    print_line(output, '=',30 );

    for (int i = 0; i < sistemaHuellitas.numMascotas; i++) {
        output << sistemaHuellitas.mascotas[i];
        int centinela = 0;
        for (int j = 0; j < sistemaHuellitas.numAtencions; j++) {
            if (sistemaHuellitas.atencion[j].idMascota ==sistemaHuellitas.mascotas[i].idMascota) {
                output << sistemaHuellitas.atencion[j];
                centinela = 1;
            }

        }
        if (centinela ==0) {
            output << "No tiene intenciones registradas" << endl;
        }
        print_line(output, '-',30 );


    }
}
