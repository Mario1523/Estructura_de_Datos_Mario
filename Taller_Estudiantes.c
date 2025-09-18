/*
    taller_menu.c
    Compilación: gcc taller_menu.c -o taller_menu.exe
    Autores: Carlos Mario Portocarrero Pestana, Janny Sneyder Osorio
*/

#include <stdio.h>

#define NUM_ESTUDIANTES 6

// Opciones del menú
enum OpcionesMenu {
    NOTA_MAX = 1,
    PROMEDIO,
    ORDENAR_COD,
    MOSTRAR,
    SALIR
};

typedef struct {
    int codigo;
    float nota;
} Estudiante;

// Datos predefinidos
Estudiante estudiantes[NUM_ESTUDIANTES] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 2.9},
    {2024104, 4.0},
    {2024105, 3.8},
    {2024106, 4.7}
};

// Prototipos
int mostrarMenu();
float notaMaxRec(const Estudiante arr[], int n);
float sumaNotasRec(const Estudiante arr[], int n);
void ordenarCodRec(Estudiante arr[], int n, int inicio);
int buscarMinIdx(const Estudiante arr[], int n, int inicio, int minIdx);
void mostrarEstudiantes(const Estudiante arr[], int n);

int main() {
    int opcion;
    int ordenado = 0;

    do {
        opcion = mostrarMenu();

        switch(opcion) {
            case NOTA_MAX:
                printf("Nota máxima: %.2f\n", notaMaxRec(estudiantes, NUM_ESTUDIANTES));
                break;
            case PROMEDIO:
                printf("Promedio: %.2f\n", sumaNotasRec(estudiantes, NUM_ESTUDIANTES)/NUM_ESTUDIANTES);
                break;
            case ORDENAR_COD:
                ordenarCodRec(estudiantes, NUM_ESTUDIANTES, 0);
                ordenado = 1;
                printf("Estudiantes ordenados por código.\n");
                break;
            case MOSTRAR:
                mostrarEstudiantes(estudiantes, NUM_ESTUDIANTES);
                break;
            case SALIR:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != SALIR);

    return 0;
}

int mostrarMenu() {
    int op;
    printf("\n=== MENÚ ===\n");
    printf("1. Nota máxima (recursivo)\n");
    printf("2. Promedio (recursivo)\n");
    printf("3. Ordenar por código (Selection Sort Recursivo)\n");
    printf("4. Mostrar estudiantes\n");
    printf("5. Salir\n");
    printf("Opción: ");
    scanf("%d", &op);
    return op;
}

// Recursivo: nota máxima
float notaMaxRec(const Estudiante arr[], int n) {
    if (n == 1) return arr[0].nota;
    float maxRest = notaMaxRec(arr, n-1);
    return (arr[n-1].nota > maxRest) ? arr[n-1].nota : maxRest;
}

// Recursivo: suma de notas
float sumaNotasRec(const Estudiante arr[], int n) {
    if (n == 0) return 0;
    return arr[n-1].nota + sumaNotasRec(arr, n-1);
}

// Recursivo: Selection Sort
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

// Recursivo: índice del menor código
int buscarMinIdx(const Estudiante arr[], int n, int inicio, int minIdx) {
    if (inicio >= n) return minIdx;
    if (arr[inicio].codigo < arr[minIdx].codigo) minIdx = inicio;
    return buscarMinIdx(arr, n, inicio+1, minIdx);
}

// Mostrar estudiantes
void mostrarEstudiantes(const Estudiante arr[], int n) {
    printf("\nCod\tNota\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%.2f\n", arr[i].codigo, arr[i].nota);
}
