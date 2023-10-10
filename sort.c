#include "library/libSort.h"
#include "stdio.h"
#include "stdlib.h"

void insertionSort(int arraySort[], int sizeArray);
void selectionSort(int arraySort[], int sizeArray);
void quickSort(int arraySort[], int startIndex, int endIndex);
void quickSortHoare(int arraySort[], int startIndex, int endIndex);

int main() {
    int arrayNumber[] = {8, 54, 12, 43, 2, 4, 6, 1, 8, 9};
    int sizeArray = sizeof(arrayNumber) / sizeof(arrayNumber[0]);
    printArray(arrayNumber, sizeArray);
    // selectionSort(arrayNumber, sizeArray);
    // quickSort(arrayNumber, 0, sizeArray - 1);
    quickSortHoare(arrayNumber, 0, sizeArray - 1);
    printArray(arrayNumber, sizeArray);
    return 0;
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
    if (startIndex >= endIndex) return;

    // printf("end index value = %d\n", endIndex);
    int a = partitionLumoto(arraySort, startIndex, endIndex);
    // printf("return value = %d\n", a);
    quickSort(arraySort, startIndex, a - 1);
    quickSort(arraySort, a + 1, endIndex);
}

void quickSortHoare(int arraySort[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;
    int a = partitionHoare(arraySort, startIndex, endIndex);
    quickSortHoare(arraySort, startIndex, a);
    quickSortHoare(arraySort, a + 1, endIndex);
}
