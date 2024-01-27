#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void generateRandomArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        //Reducir las opciones a numeros menores a 100
        array[i] = rand() % 100;
    }
}

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Hola desde el hilo %d\n", id);
    }

    srand(time(NULL));
    const int size = 1000;

    int arrayA[size];
    generateRandomArray(arrayA, size);

    int arrayB[size];
    generateRandomArray(arrayB, size);


    printf("Array 1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arrayA[i]);
    }

    printf("\n\nArray 2:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arrayB[i]);
    }

    return 0;
}
