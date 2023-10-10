#ifndef __LIB_SORT_H
#define __LIB_SORT_H

#include "stdio.h"
#include "stdlib.h"

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arrayPrint[], int sizeArray) {
    for (int i = 0; i < sizeArray; i++) {
        printf("%d ", arrayPrint[i]);
    }
    printf("\n");
}

int partitionLumoto(int arraySort[], int startIndex, int endIndex) {
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

int partitionHoare(int arraySort[], int startIndex, int endIndex) {
    // choosing pivot is first element
    int pivot = arraySort[startIndex];
    int i = startIndex - 1;
    int j = endIndex + 1;
    while (1) {
        do {
            i++;
        } while (arraySort[i] < pivot);  // don't using "=" because we won't change the pivot's value
        do {
            j--;
        } while (arraySort[j] > pivot);
        if (i < j) {
            swap(&arraySort[i], &arraySort[j]);
        } else
            return j;
    }
}

int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the first element as the pivot
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        // Swap arr[i] and arr[j]
        swap(&arr[i], &arr[j]);
    }
}

#endif