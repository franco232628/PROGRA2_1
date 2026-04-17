//
// Created by HP on 16/04/2026.
//

#ifndef EJERCICIO_AUXILIARYFUNCTIONS_HPP
#define EJERCICIO_AUXILIARYFUNCTIONS_HPP

#include "Mylibreria.hpp"
#include "SistemaHuellitas.hpp"

void cargarDatos(const char *file_name1, const char *file_name2,
                 struct SistemaHuellitas &sistemaHuellitas);

void open_read(ifstream &input, const char *file_name1);

void open_print(ofstream &output, const char *file_name);

void registrarAtenciones(const char *file_name,
                         struct SistemaHuellitas &sistemaHuellitas);

bool veterinarioOcupado( Atencion atencion,
                         struct SistemaHuellitas sistemaHuellitas);

void imprimirListaMascotaAEsteriizar(const char * file_name,
     struct SistemaHuellitas sistemaHuellitas);
void print_line( ofstream & output, char carac, int MAX);
void imprimirTodo(const char * file_name,  struct SistemaHuellitas  sistemaHuellitas);

#endif //EJERCICIO_AUXILIARYFUNCTIONS_HPP
