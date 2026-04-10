#ifndef BIBLIOTECA2025_1_FUENTES_LIBRARY_H
#define BIBLIOTECA2025_1_FUENTES_LIBRARY_H
#include "Estructuras.hpp"
void operator !(CadenaDeCaracteres &c);

void operator <=(CadenaDeCaracteres &cadena, int memoria);

void operator <=(CadenaDeCaracteres &cadena, char *cad);

void operator <=(CadenaDeCaracteres &cadena1, CadenaDeCaracteres &cadena2);

bool operator +=(CadenaDeCaracteres &cadena, char *cad);

bool operator +=(CadenaDeCaracteres &cadena1, CadenaDeCaracteres &cadena2);

int compare(struct CadenaDeCaracteres &cadena, char *cad);

bool operator==(struct CadenaDeCaracteres &cadena, char *cad);

bool operator>(struct CadenaDeCaracteres &cadena, char *cad);

bool operator<(struct CadenaDeCaracteres &cadena, char *cad);

int compare(struct CadenaDeCaracteres &cadena1, struct CadenaDeCaracteres &cadena2);

bool operator==(struct CadenaDeCaracteres &cadena1, struct CadenaDeCaracteres &cadena2);

bool operator>(struct CadenaDeCaracteres &cadena1,
               struct CadenaDeCaracteres &cadena2);

bool operator<(struct CadenaDeCaracteres &cadena1,
               struct CadenaDeCaracteres &cadena2);

void operator&&(struct CadenaDeCaracteres &cadena1,
                struct CadenaDeCaracteres &cadena2);

int operator>>(ifstream &input, struct CadenaDeCaracteres &cadena);

void operator<<(ofstream &output, struct CadenaDeCaracteres &cadena);


#endif // BIBLIOTECA2025_1_FUENTES_LIBRARY_H
