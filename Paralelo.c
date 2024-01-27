#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
}

int main() {
    srand(time(NULL));
    const int size = 1000;

    int arrayA[size];
    generateRandomArray(arrayA, array_size);

    int arrayB[size];
    generateRandomArray(arrayB, array_size);


    printf("Array 1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array1[i]);
    }

    printf("\n\nArray 2:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array2[i]);
    }

    return 0;
}
