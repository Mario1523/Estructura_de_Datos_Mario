#include <stdio.h>

#define TAM 10  // Tamaño fijo del arreglo

// Prototipos
void llenarArray(int a[], int n);
void mostrarArray(const int a[], int n);
void ordenarSelectionAscendente(int a[], int n);
void ordenarInsertionDescendente(int a[], int n);

int main() {
    int arreglo[TAM];
    int opcion;
    int datosLlenos = 0; // Bandera para saber si se llenó el arreglo

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Llenar arreglo\n");
        printf("2. Mostrar arreglo original\n");
        printf("3. Ordenar (Selection Sort Ascendente)\n");
        printf("4. Ordenar (Insertion Sort Descendente)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                llenarArray(arreglo, TAM);
                datosLlenos = 1;
                break;
            case 2:
                if (datosLlenos)
                    mostrarArray(arreglo, TAM);
                else
                    printf("Primero debe llenar el arreglo.\n");
                break;
            case 3:
                if (datosLlenos)
                    ordenarSelectionAscendente(arreglo, TAM);
                else
                    printf("Primero debe llenar el arreglo.\n");
                break;
            case 4:
                if (datosLlenos)
                    ordenarInsertionDescendente(arreglo, TAM);
                else
                    printf("Primero debe llenar el arreglo.\n");
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

// Solicita al usuario 10 números positivos y los almacena en el arreglo
void llenarArray(int a[], int n) {
    printf("\nIngrese %d numeros enteros positivos:\n", n);
    for (int i = 0; i < n; i++) {
        int valor;
        do {
            printf("Elemento [%d]: ", i);
            scanf("%d", &valor);
            if (valor <= 0) {
                printf("Valor no valido. Ingrese un numero positivo.\n");
            }
        } while (valor <= 0);
        a[i] = valor;
    }
}

// Muestra el contenido del arreglo en formato [x, y, z]
void mostrarArray(const int a[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Selection Sort: ordena de menor a mayor mostrando cada paso
void ordenarSelectionAscendente(int a[], int n) {
    printf("\n--- Selection Sort (Ascendente) ---\n");
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) { // Intercambio solo si se encontró un menor
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
        printf("Paso %d: ", i + 1);
        mostrarArray(a, n);
    }
    printf("Resultado final: ");
    mostrarArray(a, n);
}

// Insertion Sort: ordena de mayor a menor mostrando cada paso
void ordenarInsertionDescendente(int a[], int n) {
    printf("\n--- Insertion Sort (Descendente) ---\n");
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        // Desplaza a la derecha los elementos menores que 'key'
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printf("Paso %d: ", i);
        mostrarArray(a, n);
    }
    printf("Resultado final: ");
    mostrarArray(a, n);
}
