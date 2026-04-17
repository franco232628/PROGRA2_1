//
// Created by HP on 16/04/2026.
//

#ifndef UNTITLED1_SISTEMAHUELLITAS_HPP
#define UNTITLED1_SISTEMAHUELLITAS_HPP

#include "Mascota.hpp"
#include "Veterinario.hpp"
#include "Atencion.hpp"

struct SistemaHuellitas {
    struct Mascota mascotas[20];
    struct Veterinario veterinario[10];
    struct Atencion atencion[15];

    int numMascotas;
    int numVeterinarios;
    int numAtencions;
};


#endif //UNTITLED1_SISTEMAHUELLITAS_HPP
