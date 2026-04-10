#include "library.h"

int main() {
    Alumnos a1, a2, a3;
    a1.codigo=1;
    a2.codigo=2;
    a3.codigo=3;
    Alumnos arreglo_alumnos[5];
    arreglo_alumnos[0]=a1;
    arreglo_alumnos[1]=a2;
    arreglo_alumnos[2]=a3;
    arreglo_alumnos[3].codigo=0;
    Alumnos a5;
    a5.codigo=7;
    cout<<(arreglo_alumnos<=a5)<<endl;
    return 0;
}