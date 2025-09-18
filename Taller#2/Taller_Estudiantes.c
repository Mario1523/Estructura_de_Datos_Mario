// Función recursiva para ordenar por código (Selection Sort)
void ordenarCodRec(Estudiante arr[], int n, int inicio) {
    if (inicio >= n-1) return;
    int minIdx = buscarMinIdx(arr, n, inicio, inicio);
    if (minIdx != inicio) {
        Estudiante tmp = arr[inicio];
        arr[inicio] = arr[minIdx];
        arr[minIdx] = tmp;
    }
    ordenarCodRec(arr, n, inicio+1);
}

// Función recursiva para buscar el índice del menor código
int buscarMinIdx(const Estudiante arr[], int n, int inicio, int minIdx) {
    if (inicio >= n) return minIdx;
    if (arr[inicio].codigo < arr[minIdx].codigo) minIdx = inicio;
    return buscarMinIdx(arr, n, inicio+1, minIdx);
}

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
