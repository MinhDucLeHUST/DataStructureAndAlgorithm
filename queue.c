/*Queue working as First in First out*/
#include "stdio.h"
#include "stdlib.h"

#define SIZE_QUEUE 100

/*Declare funtion*/
void enqueue();
void dequeue();
void show();

/*
    front is index that is located at the head of queue, when we remove a element into queue => front = front + 1
    rear is index that is located at the tail of queue, when we add a element into queue => rear = rear + 1
*/
int front = 0;
int rear = 0;
int arrayQueue[SIZE_QUEUE];

int main() {
    int choiceNumber;
    int index;
    printf("*********************************************************\n");
    printf("\tHere are some function to use queue!\n");
    printf("\t0. Insert new element for queue\n\t1. Get value and remove it outside queue\n\t2. Show all remain element in queue\n");
    printf("*********************************************************\n");
    while (1) {
        printf("\nEnter your choice (use numerical order) below here: ");
        scanf("%d", &choiceNumber);
        switch (choiceNumber) {
            case 0:
                enqueue();
                break;
            case 1:
                dequeue();
                break;
            case 2:
                show();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("....");
                break;
        }
    }
}

/*Push data into queue*/
void enqueue() {
    int valueEnqueue = 0;
    printf("Case 0: Enter data into queue: ");
    scanf("%d", &valueEnqueue);
    if (rear == SIZE_QUEUE) {
        printf("Queue is full!");
    } else {
        arrayQueue[rear] = valueEnqueue;
        rear += 1;
    }
}

/*Remove data out of queue*/
void dequeue() {
    printf("Case 1: Get front element then remove it outside queue\n");
    if (front == rear || front > rear) {
        printf("Queue is empty! || Underflow\n");
    } else {
        printf("Remove element outside queue: %d", arrayQueue[front]);
        front += 1;
    }
}

void show() {
    printf("Case 2: Show all element in queue\n");
    if (front == rear || front > rear) {
        printf("Queue is empty! || Underflow\n");
    } else {
        for (int i = front; i < rear; i++) {
            printf("\t%d", arrayQueue[i]);
        }
    }
}

/*This function is not used*/
void getDataInsideQueue() {
    int index;
    if (front == rear || front > rear) {
        printf("Queue is empty! || Underflow\n");
    }
    printf("Insert position: ");
    scanf("%d", &index);
    if (index < 0 || index > rear) {
        printf("Fail");
    } else {
        printf("Value at %d = %d", index, arrayQueue[index]);
    }
}
