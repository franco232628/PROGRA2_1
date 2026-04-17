//
// Created by HP on 16/04/2026.
//

#include "Mylibreria.hpp"



char * asignar_cadena(char *buffer) {
    char *str;
    str = new char[strlen(buffer) + 1]{};
    strcpy(str, buffer);
    return str;
}



char *read_str(ifstream &input, int MAX, char delim){
    char buffer[MAX];
    input >> ws;
    input.getline(buffer, MAX, delim);
    if (input.eof()) return nullptr;
    return asignar_cadena(buffer);
}

int read_int(ifstream &input) {
    int num;
    input >> num;
    input.get();
    return num;
}

int read_date(ifstream &input) {
    int dd, mm, aaaa;
    char c;
    input >> dd >> c >> mm >> c >> aaaa;
    return aaaa*10000 + mm*100 + dd;
}
//lecturA:


ifstream& operator>>(ifstream &input, Mascota &mascota) {
    // 101,Luna,Labrador,Negro,CANINO,10/10/2024
    if (!(input >> mascota.idMascota)) return input;
    input.get();
    mascota.nombre=read_str(input,30,',' );
    mascota.raza=read_str(input,15,',' );
    mascota.color=read_str(input,15,',' );
    mascota.tipo = read_str(input,15,',' );
    mascota.fechaNacimiento = read_date(input);
    input.get();
    return input;
}

int read_time(ifstream &input) {
    int hh, mm;
    char c;

    input >> hh>>c>>mm;
    return hh*3600 + mm*60;
}

ifstream& operator>>(ifstream &input, Veterinario &veterinario) {
    if (!(input >> veterinario.idVeterinario)) return input;
    input.get();

    veterinario.nombre=read_str(input,30,',' );
    veterinario.especialidad=read_str(input,20,'\n' );
    return input;
}



ifstream& operator>>(ifstream &input, Atencion &atencion) {

    if (!(input >> atencion.idMascota)) return input;
    input.get();
    atencion.idVeterinario = read_int(input);
    atencion.fecha= read_date(input);
    input.get();
    atencion.tipoAtencion = read_str(input,15,',' );
    atencion.horayMinutos = read_time(input);
    input.get();
    atencion.estado = read_str(input, 15, '\n');
    return input;

}

//Operaciones:

bool operator==(Atencion a, Atencion b) {
    return (a.idVeterinario == b.idVeterinario &&
            a.fecha == b.fecha &&
            a.horayMinutos == b.horayMinutos);
}

bool operator<=( Mascota mascota, int fechaComparar) {
    return mascota.fechaNacimiento<=fechaComparar;
}

//Impresion:

void operator<<(ofstream &output, Mascota mascota) {
    output << "ID: " << mascota.idMascota << endl;
    output << right << setw(11) << "Nombre: " << mascota.nombre << endl;
    output << setw(9) << "Raza: " << mascota.raza << endl;
    output << setw(10) << "Color: " << mascota.color << endl;
    output << setw(9) << "Tipo: " << mascota.tipo << endl;
}

void operator<<(ofstream &output, Atencion atencion) {
    output << "Fecha: " << atencion.fecha
    << ", ID: "<< atencion.idAtencion <<", Veterinario: "
    << atencion.idVeterinario <<", Tipo: " << atencion.tipoAtencion <<
        ", Estado: " << atencion.estado << endl;
}

