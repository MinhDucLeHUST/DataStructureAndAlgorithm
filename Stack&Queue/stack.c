/*Stack working as last in first out*/
#include "stdio.h"
#include "stdlib.h"

#define SIZE_STACK 100

int topStack = -1;
int arrayStack[SIZE_STACK];

/*Declare function*/
void push();
void pop();
void show();
void getRamdomValue(int index);

int main() {
    int numberChoice;
    int index;
    printf("Hello, i'm studying about Stack. Here some choices in my program: \n");
    printf("1. Push data into stack ^_^ push()\n2. Get data on top of stack ^_^ pop()\n3. Get ramdom data of stack\n4. Show all elements inside stack ^_^ show()\n5. Exit program ^_^ exit()\n");
    while (1) {
        printf("\nEnter your choice (use numerical order) below here: ");
        scanf("%d", &numberChoice);
        if (numberChoice == 3) {
            printf("\nEnter position which is getting in stack: ");
            scanf("%d", &index);
        }
        switch (numberChoice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                getRamdomValue(index);
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!!");
        }
    }
}

void push() {
    int valuePush = 0;
    if (topStack == SIZE_STACK - 1) {
        printf("Over flow!");
    } else {
        printf("Insert value which you wanna push into stack: ");
        scanf("%d", &valuePush);
        topStack = topStack + 1;
        arrayStack[topStack] = valuePush;
    }
}

void pop() {
    if (topStack == -1) {
        printf("Under flow");
    } else {
        printf("Get %d out of stack\n", arrayStack[topStack]);
        topStack -= 1;
        printf("Elements remaining in stack:");
        for (int i = topStack; i >= 0; i--) {
            printf("\t%d", arrayStack[i]);
        }
    }
}

void show() {
    if (topStack == -1) {
        printf("Under flow");
    } else {
        printf("\n=========== All elements in stack ==============\n");
        for (int i = topStack; i >= 0; i--) {
            printf("\t%d", arrayStack[i]);
        }
        printf("\n==================== End =======================\n");
    }
}

/*Get data from custom position but i don't remove it out of stack*/
void getRamdomValue(int index) {
    if (index < 0 || index > SIZE_STACK) {
        printf("Index is failed");
    }
    if (topStack == -1) {
        printf("Under flow");
    } else {
        printf("Get value at %d position of stack = %d", index, arrayStack[index]);
        // topStack -= 1;
    }
}