#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void sumArrays(int arrayA[], int arrayB[], int arrayR[], int size) {
    int thread_num = 0;

    #pragma omp parallel sections
    {
        // Primera mitad
        #pragma omp section
        {
            thread_num = omp_get_thread_num();
            printf("Hilo %d que suma la primera mitad \n", thread_num);
            for (int i = 0; i < size / 2; i++) {
                arrayR[i] = arrayA[i] + arrayB[i];
            }
        }
        //Segunda mitad
        #pragma omp section
        {
            thread_num = omp_get_thread_num();
            printf("Hilo %d que suma la segunda mitad \n", thread_num);
            for (int i = size / 2; i < size; i++) {
                arrayR[i] = arrayA[i] + arrayB[i];
            }
        }
    }
}

void generateRandomArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        //Reducir las opciones a numeros menores a 100
        array[i] = rand() % 100;
    }
}

int main() {

    srand(time(NULL));
    const int size = 1000;

    int arrayA[size];
    generateRandomArray(arrayA, size);

    int arrayB[size];
    generateRandomArray(arrayB, size);

    int arrayR[size];
    sumArrays(arrayA, arrayB, arrayR, size);

    printf("Array A:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arrayA[i]);
    }

    printf("\n\nArray B:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arrayB[i]);
    }

    printf("\n\nArray R:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arrayR[i]);
    }

    return 0;
}



