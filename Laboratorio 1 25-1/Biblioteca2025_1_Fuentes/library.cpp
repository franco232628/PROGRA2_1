#include "library.h"

void operator !(CadenaDeCaracteres &c) {
    c.cadena = nullptr;
    c.capacidad = 0;
    c.longitud = 0;
}

void operator <=(CadenaDeCaracteres &cadena, int memoria) {
    !cadena;
    cadena.cadena = new char[memoria];
    cadena.capacidad = memoria;
}

void operator <=(CadenaDeCaracteres &cadena, char *cad) {
    int len = strlen(cad);
    if (cadena.cadena == nullptr) {
        cadena <= len + 1;
    } else {
        int capacidad = cadena.capacidad;
        delete [] cadena.cadena;
        if (cadena.capacidad < len + 1) cadena <= len + 1;
        else cadena <= capacidad;
    }
    strcpy(cadena.cadena, cad);
    cadena.longitud = len;
}

void operator <=(CadenaDeCaracteres &cadena1, CadenaDeCaracteres &cadena2) {
    cadena1 <= cadena2.cadena;
}

bool operator +=(CadenaDeCaracteres &cadena, char *cad) {
    if (cadena.cadena == nullptr) return false;
    int longitud = cadena.longitud + strlen(cad);
    if (cadena.capacidad <= longitud) {
        CadenaDeCaracteres aux;
        aux <= longitud + 1;
        aux <= cadena;
        delete [] cadena.cadena;
        cadena = aux;
    }
    strcat(cadena.cadena, cad);
    cadena.longitud = strlen(cadena.cadena);
    return true;
}

bool operator +=(CadenaDeCaracteres &cadena1, CadenaDeCaracteres &cadena2) {
    return cadena1 += cadena2.cadena;
}

int compare(struct CadenaDeCaracteres &cadena, char *cad) {
    struct CadenaDeCaracteres comparar1, comparar2;
    !comparar1;
    !comparar2;
    comparar1 <= cadena;
    comparar2 <= cad;
    for (int i = 0; i < comparar1.capacidad; i++) if (comparar1.cadena[i] >= 'a' and comparar1.cadena[i] <= 'z')
        comparar1.cadena[i] = comparar1.cadena[i] - 32;
    for (int i = 0; i < comparar2.capacidad; i++) if (comparar2.cadena[i] >= 'a' and comparar2.cadena[i] <= 'z')
        comparar2.cadena[i] = comparar2.cadena[i] - 32;
    int comp = strcmp(comparar1.cadena, comparar2.cadena);
    if (comp == 0) return 0;
    if (comp > 0) return 1;
    if (comp < 0) return -1;

    return 0;
}

bool operator==(struct CadenaDeCaracteres &cadena, char *cad) {
    int comparacion = compare(cadena, cad);
    if (comparacion == 0) return true;
    else return false;
}

bool operator>(struct CadenaDeCaracteres &cadena, char *cad) {
    int comparacion = compare(cadena, cad);
    if (comparacion == 1) return true;
    else return false;
}

bool operator<(struct CadenaDeCaracteres &cadena, char *cad) {
    int comparacion = compare(cadena, cad);
    if (comparacion == -1) return true;
    else return false;
}

int compare(struct CadenaDeCaracteres &cadena1,
            struct CadenaDeCaracteres &cadena2) {
    return compare(cadena1, cadena2.cadena);
}

bool operator==(struct CadenaDeCaracteres &cadena1,
                struct CadenaDeCaracteres &cadena2) {
    int comparacion = compare(cadena1, cadena2);
    if (comparacion == 0) return true;
    else return false;
}

bool operator>(struct CadenaDeCaracteres &cadena1,
               struct CadenaDeCaracteres &cadena2) {
    int comparacion = compare(cadena1, cadena2);
    if (comparacion == 1) return true;
    else return false;
}

bool operator<(struct CadenaDeCaracteres &cadena1,
               struct CadenaDeCaracteres &cadena2) {
    int comparacion = compare(cadena1, cadena2);
    if (comparacion == -1) return true;
    else return false;
}

void operator&&(struct CadenaDeCaracteres &cadena1,
                struct CadenaDeCaracteres &cadena2) {
    struct CadenaDeCaracteres auxiliar;
    !auxiliar;
    auxiliar <= cadena1;
    cadena1 <= cadena2;
    cadena2 <= auxiliar;
}

int operator>>(ifstream &input, struct CadenaDeCaracteres &cadena) {
    if (input.eof()) return 0;
    char comprobar, buffer[100];
    comprobar = input.peek();
    int i = 0;
    if (comprobar < 'A' or comprobar > 'z') return -1;
    while (true) {
        buffer[i] = input.get();
        if (buffer[i] == ' ' or buffer[i] == '\n') break;
        i++;
    }

    buffer[i] = 0;
    cadena <= buffer;
    return 1;
}

void operator<<(ofstream &output, struct CadenaDeCaracteres &cadena) {
    output << cadena.cadena;
}
