#include "stdio.h"
#include "stdlib.h"

void insertionSort(int arraySort[], int sizeArray);
void selectionSort(int arraySort[], int sizeArray);
void printArray(int arrayPrint[], int sizeArray);
void quickSort(int arraySort[], int startIndex, int endIndex);
int partition(int arraySort[], int startIndex, int endIndex);
void swap(int* a, int* b);

int main() {
    int arrayNumber[] = {8, 54, 12, 43, 2, 4, 6, 1, 8, 9};
    int sizeArray = sizeof(arrayNumber) / sizeof(arrayNumber[0]);
    printArray(arrayNumber, sizeArray);
    // selectionSort(arrayNumber, sizeArray);
    quickSort(arrayNumber, 0, sizeArray - 1);
    // printArray(arrayNumber, sizeArray);
    return 0;
}

void printArray(int arrayPrint[], int sizeArray) {
    for (int i = 0; i < sizeArray; i++) {
        printf("%d ", arrayPrint[i]);
    }
    printf("\n");
}

// Insertion sort
void insertionSort(int arraySort[], int sizeArray) {
    for (int i = 1; i < sizeArray; i++) {
        int compNum = arraySort[i];
        int j = i - 1;
        while (j >= 0 && arraySort[j] > compNum) {
            arraySort[j + 1] = arraySort[j];
            j--;
        }
        arraySort[j + 1] = compNum;
        printArray(arraySort, sizeArray);
    }
}

// Selection sort
void selectionSort(int arraySort[], int sizeArray) {
    int minIndex = 0;
    for (int i = 0; i < sizeArray - 1; i++) {
        minIndex = i;
        // find min index in unsorted array
        for (int j = i + 1; j < sizeArray; j++) {
            if (arraySort[j] < arraySort[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arraySort[i];
            arraySort[i] = arraySort[minIndex];
            arraySort[minIndex] = temp;
        }
        printArray(arraySort, sizeArray);
    }
}

/*
    Quick sort:
        Lumoto partition: chọn phần tử cuối cùng của 1 dãy làm pivot
        Hoare partition
*/
void quickSort(int arraySort[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return;
    }
    // printf("end index value = %d\n", endIndex);
    int a = partition(arraySort, startIndex, endIndex);
    // printf("return value = %d\n", a);
    quickSort(arraySort, startIndex, a - 1);
    quickSort(arraySort, a + 1, endIndex);
}

int partition(int arraySort[], int startIndex, int endIndex) {
    int pivot = arraySort[endIndex];
    int i = startIndex - 1;
    for (int j = startIndex; j < endIndex; j++) {
        if (arraySort[j] <= pivot) {
            ++i;
            swap(&arraySort[i], &arraySort[j]);
        }
    }
    printf("pivot = %d and endIndex = %d\n", pivot, arraySort[endIndex]);
    swap(&arraySort[i + 1], &arraySort[endIndex]);
    // swap(&arraySort[i + 1], &pivot);
    printArray(arraySort, endIndex + 1);
    return i + 1;  // return patition position
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}