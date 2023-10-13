#include "library/libSort.h"
#include "stdio.h"
#include "stdlib.h"

void insertionSort(int arraySort[], int sizeArray);
void selectionSort(int arraySort[], int sizeArray);
void quickSortLumoto(int arraySort[], int startIndex, int endIndex);
void quickSortHoare(int arraySort[], int startIndex, int endIndex);
void mergeSort(int arraySort[], int startIndex, int endIndex);
// int* merge(int* arrayHalfStart[], int* arrayHalfEnd[]);

int main() {
    int arrayNumber[] = {8, 54, 12, 43, 2, 4, 6, 1, 8, 9};
    int sizeArray = sizeof(arrayNumber) / sizeof(arrayNumber[0]);
    printf("*Original array: \n");
    printArray(arrayNumber, sizeArray);
    // printf("sizeArray = %d")
    mergeSort(arrayNumber, 0, sizeArray - 1);
    printf("*Sorted array: \n");
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
        Lumoto partition: chọn phần tử cuối cùng của 1 dãy làm pivot, ta cho quét dãy số từ đầu đến phần tử n-1 của array,
                        sau đấy dựa vào điều kiện để swap giá trị sao cho sắp xếp theo đúng ý muốn của người dùng
        Hoare partition: lựa chọn phần tử làm pivot có thể đứng đầu, đứng giữa or cuối. sử dụng 2 phần tử để chạy từ đầu
                        và chạy từ cuối lên, sắp xếp theo ý muốn người dùng
    Tham khảo: https://www.youtube.com/watch?v=eT9Epyf0XLM&t=1829s
*/
void quickSortLumoto(int arraySort[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;

    // printf("end index value = %d\n", endIndex);
    int a = partitionLumoto(arraySort, startIndex, endIndex);
    // printf("return value = %d\n", a);
    quickSortLumoto(arraySort, startIndex, a - 1);
    quickSortLumoto(arraySort, a + 1, endIndex);
}

void quickSortHoare(int arraySort[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) return;
    int a = partitionHoare(arraySort, startIndex, endIndex);
    quickSortHoare(arraySort, startIndex, a);
    quickSortHoare(arraySort, a + 1, endIndex);
}

/*
    Thuật toán merge sort chia đổi array thành các array nhỏ hơn, sao cho chỉ còn 1 phần tử, sau đấy sắp xếp chúng rồi ghép lại để được 1 array như ý.
    Tham khảo: https://www.youtube.com/watch?v=CEkAzOUa2mw
*/

void mergeSort(int arraySort[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return;
    }
    int sizeArray = startIndex + endIndex;

    // Detach array
    int midIndex = sizeArray / 2;
    mergeSort(arraySort, startIndex, midIndex);
    mergeSort(arraySort, midIndex + 1, endIndex);

    // Sort child array and merge
    int indexHalfStart = midIndex - startIndex + 1;
    int indexHalfEnd = endIndex - midIndex;

    int *arrayHalfStart = (int *)malloc(indexHalfStart * sizeof(int));
    int *arrayHalfEnd = (int *)malloc(indexHalfEnd * sizeof(int));

    // int arrayHalfEnd[indexHalfEnd];
    for (int i = 0; i < indexHalfStart; i++) {
        arrayHalfStart[i] = arraySort[startIndex + i];
    }
    for (int i = 0; i < indexHalfEnd; i++) {
        arrayHalfEnd[i] = arraySort[midIndex + i + 1];
    }

    int indexResult = startIndex;  // // gán như vậy để arrayResult được gán giá trị đúng index position
    int i = 0, j = 0;
    while (i < indexHalfStart && j < indexHalfEnd) {  // check arrayHalfStart and arrayHalfEnd's array is empty?
        if (arrayHalfStart[i] <= arrayHalfEnd[j]) {
            arraySort[indexResult] = arrayHalfStart[i];
            i++;
        } else {
            arraySort[indexResult] = arrayHalfEnd[j];
            j++;
        }
        indexResult++;
    }
    // one of them is empty
    while (i < indexHalfStart) {
        arraySort[indexResult] = arrayHalfStart[i];
        indexResult++;
        i++;
    }
    while (j < indexHalfEnd) {
        arraySort[indexResult] = arrayHalfEnd[j];
        indexResult++;
        j++;
    }
}
