#include "stdio.h"
#include "stdlib.h"

/*Declare function*/
int sum(int number);
int fiboanci(int number);

/*
    1 hàm được gọi là đệ quy khi nó thực hiện gọi lại chính nó
    Khi sử dụng đệ quy, cần chú ý 2 việc:
    + Điều kiện dừng
    + Công thức truy hồi
*/

int main() {
    // int result = sum(10);
    int result = fiboanci(1);
    printf("Result = %d", result);
    return 0;
}

int sum(int number) {
    if (number == 1) {
        return 1;
    } else {
        return number + sum(number - 1);
    }
}

int fiboanci(int number) {
    if (number <= 1) {
        return number;
    } else {
        return fiboanci(number - 1) + fiboanci(number - 2);
    }
}