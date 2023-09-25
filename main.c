#include "stdio.h"
#include "stdlib.h"

void insertionSort(int arraySort[], int sizeArray);
void selectionSort(int arraySort[], int sizeArray);

void printArray(int arrayPrint[], int sizeArray);
int findMin(int arraySort[], int sizeArray, int index);
int findPos(int arraySort[], int sizeArray, int index);

int main() {
    int arrayNumber[] = {8, 54, 12, 43, 2, 4, 6, 1, 8, 9};
    int sizeArray = sizeof(arrayNumber) / sizeof(arrayNumber[0]);
    // insertionSort(arrayNumber, sizeArray);
    selectionSort(arrayNumber, sizeArray);
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
    for (int i = 0; i < sizeArray; i++) {
        int position = findPos(arraySort, sizeArray, i + 1);
        int minValue = findMin(arraySort, sizeArray, i + 1);
        if (arraySort[i] < minValue) {
            int temp = arraySort[i];
            arraySort[i] = arraySort[position];
            arraySort[position] = temp;
        }
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

int findPos(int arraySort[], int sizeArray, int index) {
    int minValue = arraySort[index];
    int position = 0;
    for (int i = index; i < sizeArray; i++) {
        if (arraySort[i] < minValue) {
            minValue = arraySort[i];
            position = i;
        }
    }
    return position;
}

int findMin(int arraySort[], int sizeArray, int index) {
    int minValue = arraySort[index];
    int position = 0;
    for (int i = index; i < sizeArray; i++) {
        if (arraySort[i] < minValue) {
            minValue = arraySort[i];
            // position = i;
        }
    }
    return minValue;
}