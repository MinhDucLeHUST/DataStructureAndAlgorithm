#include "library.h"
#include "stdio.h"
#include "stdlib.h"

/*Declare the function used*/
void insertionSort(int arraySort[], int sizeArray);
void selectionSort(int arraySort[], int sizeArray);
void quickSortLumoto(int arraySort[], int startIndex, int endIndex);
void quickSortHoare(int arraySort[], int startIndex, int endIndex);
void mergeSort(int arraySort[], int startIndex, int endIndex);
void countingSort(int arraySort[], int sizeArray);
int findMaxElementInArray(int arraySort[], int sizeArray);
void heapifyMaxHeap(int arraySort[], int sizeArray, int indexHeapify);
void heapSort(int arraySort[], int sizeArray);

int main() {
    int arrayNumber[] = {8, 54, 12, 43, 62, 48, 16, 1, 8, 9};
    int sizeArray = sizeof(arrayNumber) / sizeof(arrayNumber[0]);
    printf("*Original array: \n");
    printArray(arrayNumber, sizeArray);

    // countingSort(arrayNumber, sizeArray);
    heapSort(arrayNumber, sizeArray);

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

/*
    Counting sort: thuật toán đếm sự xuất hiện của từng phần tử trong mảng 'arraySort'.
        Step 1: chúng ta xác định giá trị lớn nhất trong mảng, từ đó khoang vùng được kích thước của mảng 'arrayIndex'
            khởi tạo tất cả các giá trị của mảng bằng 0
        Step 2: đẩy các giá trị của arraySort vào vị trí tương ứng với giá trị của nó trong arrayIndex
        Step 3: cộng giá trị của phần tử đứng trước vào phần tử đứng sau, arrayIndex[i] += arrayIndex[i-1]
        Step 4: gán giá trị của arrayOutput theo vị trí và giá trị của 2 mảng trên, việc khởi tạo thêm arrayOutput vì chúng ta cần phải sử dụng tới arraySort
        Step 5: gán lại giá trị từ arrayOutput vào arraySort
*/
void countingSort(int arraySort[], int sizeArray) {
    // Step 1
    int sizeOfArrayIndex = findMaxElementInArray(arraySort, sizeArray) + 1;
    int *arrayIndex = (int *)calloc(sizeOfArrayIndex, sizeof(int));
    int *arrayOutput = (int *)malloc(sizeArray * sizeof(int));
    // Step 2
    for (int i = 0; i < sizeArray; i++) {
        arrayIndex[arraySort[i]]++;  // increase value in arrayIndex
    }
    // Step 3
    for (int i = 1; i < sizeOfArrayIndex; i++) {
        arrayIndex[i] += arrayIndex[i - 1];
    }
    // Step 4
    for (int i = sizeArray - 1; i >= 0; i--) {
        arrayOutput[arrayIndex[arraySort[i]] - 1] = arraySort[i];
        arrayIndex[arraySort[i]]--;
    }
    // Step 5
    for (int i = 0; i < sizeArray; i++) {
        arraySort[i] = arrayOutput[i];
    }
}

int findMaxElementInArray(int arraySort[], int sizeArray) {
    int maxValue = arraySort[0];
    for (int i = 1; i < sizeArray; i++) {
        if (maxValue < arraySort[i]) {
            maxValue = arraySort[i];
        }
    }
    printf("max value = %d\n", maxValue);
    return maxValue;
}

/*
    Heap sort:
        Tư tưởng của thuật toán Heap sort là chúng ta phải xây dựng được "max heap" hoặc "min heap" để sắp xếp chúng theo thứ tự mong muốn
            + Max heap là node cha sẽ lớn hơn các node con (left & right).
            + Min heap là node cha sẽ nhỏ hơn hoặc bằng các node con (left & right).
        Step 1: tiến hành heapify từ node ở vị trí n/2 -1 đến 0, với n = tổng số node của arraySort.
        Step 2: tiến hành đổi chỗ của node root với node cuối cùng của tree, việc này để sắp xếp số giá trị lớn nhất (hoặc nhỏ nhất) về cuối mảng.
*/

void heapSort(int arraySort[], int sizeArray) {
    for (int i = sizeArray / 2 - 1; i >= 0; i--) {
        heapifyMaxHeap(arraySort, sizeArray, i);
    }
    for (int i = sizeArray - 1; i >= 0; i--) {
        swap(&arraySort[0], &arraySort[i]);
        heapifyMaxHeap(arraySort, i, 0);
    }
}

void heapifyMaxHeap(int arraySort[], int sizeArray, int indexHeapify) {
    int nodeFather = indexHeapify;
    int nodeChildLeft = 2 * indexHeapify + 1;
    int nodeChildRight = 2 * indexHeapify + 2;

    if (nodeChildLeft < sizeArray && arraySort[nodeFather] < arraySort[nodeChildLeft])
        nodeFather = nodeChildLeft;
    if (nodeChildRight < sizeArray && arraySort[nodeFather] < arraySort[nodeChildRight])
        nodeFather = nodeChildRight;

    if (nodeFather != indexHeapify) {
        swap(&arraySort[nodeFather], &arraySort[indexHeapify]);
        heapifyMaxHeap(arraySort, sizeArray, nodeFather);
    }
}
