
typedef struct {
    int codigo;
    float nota;
} Estudiante;

#define NUM_ESTUDIANTES 6

Estudiante estudiantes[NUM_ESTUDIANTES] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 2.9},
    {2024104, 4.0},
    {2024105, 3.8},
    {2024106, 4.7}
};

// Función recursiva para encontrar la nota máxima
float notaMaxRec(const Estudiante arr[], int n) {
    if (n == 1) return arr[0].nota;
    float maxRest = notaMaxRec(arr, n-1);
    return (arr[n-1].nota > maxRest) ? arr[n-1].nota : maxRest;
}

// Función recursiva para sumar las notas
float sumaNotasRec(const Estudiante arr[], int n) {
    if (n == 0) return 0;
    return arr[n-1].nota + sumaNotasRec(arr, n-1);
}
