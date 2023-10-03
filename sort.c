#include "stdio.h"
#include "stdlib.h"

void insertionSort(int arraySort[], int sizeArray);
void selectionSort(int arraySort[], int sizeArray);
void printArray(int arrayPrint[], int sizeArray);

int main() {
    int arrayNumber[] = {8, 54, 12, 43, 2, 4, 6, 1, 8, 9};
    int sizeArray = sizeof(arrayNumber) / sizeof(arrayNumber[0]);
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
void selectionSort (int arraySort[], int sizeArray){
    int minIndex = 0;
    for(int i=0;i<sizeArray-1;i++){
        minIndex = i;
        //find min index in unsorted array
        for(int j = i+1;j<sizeArray;j++){
            if(arraySort[j] < arraySort[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arraySort[i];
            arraySort[i] = arraySort[minIndex];
            arraySort[minIndex] = temp;
        }
        printArray(arraySort, sizeArray);
    }
}

void printArray(int arrayPrint[], int sizeArray) {
    for (int i = 0; i < sizeArray; i++) {
        printf("%d ", arrayPrint[i]);
    }
    printf("\n");
}