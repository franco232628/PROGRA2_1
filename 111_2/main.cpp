#include "library.h"

int main() {
    // =========================
    // 🔹 1. CREAR ALUMNOS
    // =========================
    Alumnos a1, a2, a3;
    a1.codigo = 1; a1.tipo = 'P';
    a2.codigo = 2; a2.tipo = 'S';
    a3.codigo = 3; a3.tipo = 'V';

    Alumnos arrAlumnos[5];
    arrAlumnos[0] = a1;
    arrAlumnos[1] = a2;
    arrAlumnos[2] = a3;
    arrAlumnos[3].codigo = 0; // fin

    // =========================
    // 🔹 2. PROBAR <= (buscar alumno)
    // =========================
    Alumnos buscar;
    buscar.codigo = 2;

    int indiceAlumno = (arrAlumnos <= buscar);
    cout << "Indice alumno (esperado 1): " << indiceAlumno << endl;

    // =========================
    // 🔹 3. CREAR CURSOS
    // =========================
    Cursos c1, c2;

    c1.codigo = (char*)"INF263";
    c1.nombre = (char*)"Algoritmia";
    c1.docente = (char*)"Profe1";
    c1.numpresencial = 0;
    c1.numsemipresencial = 0;
    c1.numvirtual = 0;

    c2.codigo = (char*)"MAT241";
    c2.nombre = (char*)"Calculo";
    c2.docente = (char*)"Profe2";
    c2.numpresencial = 0;
    c2.numsemipresencial = 0;
    c2.numvirtual = 0;

    Cursos arrCursos[5];
    arrCursos[0] = c1;
    arrCursos[1] = c2;
    arrCursos[2].codigo = nullptr; // fin

    // =========================
    // 🔹 4. PROBAR >= (buscar curso)
    // =========================
    Cursos buscarCurso;
    buscarCurso.codigo = (char*)"MAT241";

    int indiceCurso = (arrCursos >= buscarCurso);
    cout << "Indice curso (esperado 1): " << indiceCurso << endl;

    // =========================
    // 🔹 5. PROBAR += (matricular)
    // =========================
    arrCursos[0] += arrAlumnos[0]; // P
    arrCursos[0] += arrAlumnos[1]; // S
    arrCursos[0] += arrAlumnos[2]; // V

    cout << "Presencial (1): " << arrCursos[0].numpresencial << endl;
    cout << "Semi (1): " << arrCursos[0].numsemipresencial << endl;
    cout << "Virtual (1): " << arrCursos[0].numvirtual << endl;

    // =========================
    // 🔹 6. PROBAR > (comparaciones)
    // =========================
    cout << "Alumno == codigo 1: " << (a1 > 1) << endl; // 1 (true)
    cout << "Curso == INF263: " << (c1 > (char*)"INF263") << endl; // 1

    // =========================
    // 🔹 7. PROBAR ++ (actualizar curso)
    // =========================
    ++arrCursos[0];

    cout << "Tipo final: " << arrCursos[0].tipofinal << endl;

    // =========================
    // 🔹 8. PROBAR << (reporte)
    // =========================
    ofstream out("reporte.txt");
    out << arrCursos[0];
    out.close();

    cout << "Reporte generado en reporte.txt" << endl;

    return 0;
}