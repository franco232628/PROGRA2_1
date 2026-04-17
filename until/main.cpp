#include "Biblioteca/faltas.hpp"

int main() {

    Faltas f{};

    cargar_faltas(f);
    imprimir_reporte(f);

    return 0;
}