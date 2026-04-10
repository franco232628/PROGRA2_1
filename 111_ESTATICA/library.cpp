#include "library.h"


char * asignar_cadena(char *buffer) {
    char *str;
    str = new char[strlen(buffer) + 1]{};
    strcpy(str, buffer);
    return str;
}



char *read_str(ifstream &input, int MAX, char delim) {
    char *str, buffer[MAX];
    input >> ws;
    input.getline(buffer, MAX, delim);
    if (input.eof()) return nullptr;
    return asignar_cadena(buffer);
}

double read_double(ifstream &input) {
    double num;
    input >> num;
    input.get();
    return num;
}

int read_int(ifstream &input) {
    int num;
    input >> num;
    input.get();
    return num;
}


//Lectura
void operator>>(ifstream &input, Cursos &curso) {
    // INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
    int ignorar;
    curso.codigo = read_str(input, 10, ',');
    curso.nombre = read_str(input, 80, ',');
    curso.creditos = read_double(input);
    ignorar = read_int(input);
    curso.docente = read_str(input, 80, '\n');
    curso.numpresencial = 0;
    curso.numsemipresencial = 0;
    curso.numvirtual = 0;
}

void operator>>(ifstream &input, Alumnos &alumno) {
    // 202111260,GORDILLO/CASTRO/RONAL,P
    alumno.codigo = read_int(input);
    alumno.nombre = read_str(input, 80, ',');
    alumno.tipo = input.get();
    input.get();
}


//Operaciones

bool operator>(struct Alumnos alumno, int codigoAlumno) {
    return alumno.codigo == codigoAlumno;
}


bool operator>(struct Cursos cursos, char *codigoCurso) {
    return strcmp(cursos.codigo, codigoCurso) == 0;
}

void operator+=(struct Cursos &cursos,struct Alumnos &alumnos) {
    if (alumnos.tipo == 'P') {
        int indice1 = cursos.numpresencial;
        cursos.presencial[indice1] = alumnos;
        cursos.numpresencial++;
    }
    if (alumnos.tipo == 'S') {
        int indice2 = cursos.numsemipresencial;
        cursos.semipresencial[indice2] = alumnos;
        cursos.numsemipresencial++;
    }
    if (alumnos.tipo == 'V') {
        int indice3 = cursos.numvirtual;
        cursos.vvirtual[indice3] = alumnos;
        cursos.numvirtual++;
    }
}

int operator<=(struct Alumnos *arrAlumnos, struct Alumnos alumno) {
    int i = 0;
    while (true) {
        if (arrAlumnos[i].codigo == 0) break;
        if (arrAlumnos[i].codigo == alumno.codigo) return i;
        i++;
    }
    return -1;
}


int operator>=(struct Cursos *arrCursos, struct Cursos cursos) {
    int i = 0;
    while (true) {
        if (arrCursos[i].codigo == nullptr) break;
        if (strcmp(arrCursos[i].codigo, cursos.codigo) == 0) return i;
        i++;
    }
    return -1;
}



void operator++(struct Cursos &cursos) {
    double porcentaje_presencial;
    int total_alumnos = cursos.numpresencial + cursos.numsemipresencial
                        + cursos.numvirtual;
    porcentaje_presencial = ((double)cursos.numpresencial / (double)total_alumnos)*100;

    if (porcentaje_presencial >= 50) {
        char mensaje[50]= "La clase se dictara en aula";
        cursos.tipofinal = asignar_cadena(mensaje);
    }
    else {
        char mensaje2[50]= "La clase se dictara 100% virtual";
        cursos.tipofinal = asignar_cadena(mensaje2);
    }
}

//Impresion


void operator<<(ofstream &output, struct Cursos &cursos) {
    output<<cursos.codigo<<setw(10)<<" "<<cursos.nombre<<endl;
    output<<cursos.docente<<endl;
    output<<"Alumnos presenciales:"<<setw(10)<<" "<<setw(3)<<cursos.numpresencial<<endl;
    output<<"Alumnos semipresenciales:"<<setw(6)<<" "<<setw(3)<<cursos.numsemipresencial<<endl;
    output<<"Alumnos virtuales:"<<setw(13)<<" "<<setw(3)<<cursos.numvirtual<<endl;
    output<<cursos.tipofinal<<endl;
}



