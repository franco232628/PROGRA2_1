#include "library.h"

//INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
void operator >> (ifstream &input, Cursos &curso) {
    int ignorar;
    curso.codigo = LeerConDelimitador(input, ',');
    curso.nombre = LeerConDelimitador(input, ',');
    input>>curso.creditos;
    input.get();
    input>>ignorar;
    input.get();
    curso.docente = LeerConDelimitador(input, '\n');
    curso.numpresencial=0;
    curso.numsemipresencial=0;
    curso.numvirtual=0;
}
//202111260,GORDILLO/CASTRO/RONAL,P
void operator >> (ifstream &input, Alumnos &alumno) {
    input>>alumno.codigo;
    input.get();
    alumno.nombre = LeerConDelimitador(input, ',');
    alumno.tipo = input.get();
    input.get();
}


bool operator > (struct Alumnos alumnos, int codigoalumno) {
    return alumnos.codigo == codigoalumno;
}


bool operator > (struct Cursos cursos, char *codigo) {
    return strcmp(cursos.codigo, codigo)==0;
}

void operator +=(struct Cursos &curso, struct Alumnos &alumno) {
    if (alumno.tipo=='P') {
        int indice = curso.numpresencial;
        curso.presencial[indice]=alumno;
        curso.numpresencial++;
    }
    if (alumno.tipo=='V') {
        int indice = curso.numvirtual;
        curso.vvirtual[indice]=alumno;
        curso.numvirtual++;
    }
    if (alumno.tipo=='S') {
        int indice= curso.numsemipresencial;
        curso.semipresencial[indice]= alumno;
        curso.numsemipresencial++;
    }
}

char *LeerConDelimitador(ifstream &input, char delimitador) {
    char *cadena, cad[100];
    input.getline(cad, 100, delimitador);
    cadena = new char[strlen(cad) + 1];
    strcpy(cadena, cad);
    return cadena;
}

int operator <=(struct Alumnos *arrAlumnos, struct Alumnos alumno) {
    int i=0;
    while (true) {
        if (arrAlumnos[i].codigo==0) break;
        if (arrAlumnos[i].codigo==alumno.codigo) return i;
        i++;
    }
    return -1;
}
int operator >=(struct Cursos *arrCursos, struct Cursos curso) {
    int i=0;
    while (true) {
        if (arrCursos[i].codigo==nullptr) break;
        if (strcmp(arrCursos[i].codigo, curso.codigo)==0) return i;
        i++;
    }
    return -1;
}
void operator ++(struct Cursos &curso) {
    double porcentaje_presencial;
    int total_alumnos = curso.numpresencial + curso.numsemipresencial +
        curso.numvirtual;
    porcentaje_presencial = ((double)(curso.numpresencial)/total_alumnos)*100;
    if (porcentaje_presencial>=50) {
        char mensaje[60]="La clase se dictara en aula";
        curso.tipofinal = new char[strlen(mensaje)+1];
        strcpy(curso.tipofinal, mensaje);
    }
    else {
        char mensaje[60]="La clase se dictara 100% virtual";
        curso.tipofinal = new char[strlen(mensaje)+1];
        strcpy(curso.tipofinal, mensaje);
    }
}
void operator <<(ofstream &output, struct Cursos &cursos) {
    output<<cursos.codigo<<setw(10)<<" "<<cursos.nombre<<endl;
    output<<cursos.docente<<endl;
    output<<"Alumnos presenciales:"<<setw(10)<<" "<<setw(3)<<cursos.numpresencial<<endl;
    output<<"Alumnos semipresenciales:"<<setw(6)<<" "<<setw(3)<<cursos.numsemipresencial<<endl;
    output<<"Alumnos virtuales:"<<setw(13)<<" "<<setw(3)<<cursos.numvirtual<<endl;
    output<<cursos.tipofinal<<endl;
}