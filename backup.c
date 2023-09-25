#include "stdio.h"
#include "stdlib.h"

void printArray(int arrayPrint[], int sizeArray);
void insertionSort(int arraySort[]);

int main() {
    int arrayNumber[] = {8, 54, 12, 43, 2, 4, 6, 1, 8, 9};
    // insertionSort(arrayNumber);
    int sizeArray = sizeof(arrayNumber) / sizeof(arrayNumber[0]);

    for (int i = 1; i < sizeArray; i++) {
        int compNum = arrayNumber[i];
        int j = i - 1;
        while (j >= 0 && arrayNumber[j] > compNum) {
            arrayNumber[j + 1] = arrayNumber[j];
            j--;
        }
        arrayNumber[j + 1] = compNum;
        printArray(arrayNumber, sizeArray);
    }
    return 0;
}

// Insertion sort
void insertionSort(int arraySort[]) {
    int sizeArray = sizeof(*arraySort) / sizeof(arraySort[0]);
    // size_t sizeArray = sizeof(arraySort);
    // int sizeArray = sizeof(arraySort) / sizeof(arraySort[0]);
    for (int i = 1; i < sizeArray; i++) {
        int compNum = arraySort[i];
        int j = i - 1;
        while (i >= 0 && arraySort[j] > compNum) {
            arraySort[j + 1] = arraySort[j];
            j--;
        }
        arraySort[j + 1] = compNum;
        printArray(arraySort, sizeArray);
    }
}

void swapPosition(int a, int b) {
    int temp = b;
    b = a;
    a = temp;
}

void printArray(int arrayPrint[], int sizeArray) {
    for (int i = 0; i < sizeArray; i++) {
        printf("%d ", arrayPrint[i]);
    }
    printf("\n");
}