//
// Created by HP on 16/04/2026.
//

#ifndef UNTITLED1_LIBRERIA_HPP
#define UNTITLED1_LIBRERIA_HPP

#include "Atencion.hpp"
#include "Veterinario.hpp"
#include "Mascota.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>


using namespace std;

char * asignar_cadena(char *buffer) ;

char *read_str(ifstream &input, int MAX, char delim);

int read_int(ifstream &input);

int read_date( ifstream & input);
int read_time( ifstream & input);


ifstream& operator>>(ifstream &input,  Mascota &mascota);
ifstream& operator>>(ifstream &input, Veterinario &veterinario);
ifstream& operator>>(ifstream &input, Atencion &atencion);
bool operator==(Atencion a, Atencion b) ;
bool operator<=( Mascota mascota, int fechaComparar) ;
void operator<<(ofstream &output, Mascota mascota);
void operator<<(ofstream &output, Atencion atencion);

#endif //UNTITLED1_LIBRERIA_HPP
