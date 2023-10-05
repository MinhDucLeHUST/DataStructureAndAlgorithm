/*
    Using Linked list for stack: we have unlimited number of nodes that we create
    Select starting linked list is top of stack
*/


#include "stdio.h"
#include "stdlib.h"

int numberElements = 0;

/*Declare function*/
void push (int valuePush);
void pop ();
void display();
void isEmpty();
void cleanStack();

struct Node {
    int value;
    struct Node * next;
}*top,*top1,*temp;



int main(){
    int choiceNumber;
    int valueInsert;
    printf("Here is example about Stack using Linked List in C programming\nChoose the choice to perform corresponding function:\n");
    printf("\t1. Push data\n\t2. Get data at top\n\t3. Check stack is empty\n\t4. Clear stack\n\t5. Display all elements\n\t6. Exit program\n");
    while(1){
        printf("\n*Choose action: ");
        scanf("%d", &choiceNumber);
        switch(choiceNumber){
            case 1:
                printf("Enter value: ");
                scanf("%d", &valueInsert);
                push(valueInsert);
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                cleanStack();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("...\n");
                break;

        }
    }
    return 0;
}


void push (int valuePush){
    if(top == NULL){
        top = (struct Node*)malloc(1*sizeof(struct Node));
        top->next = NULL;
        top->value = valuePush;
    } else {
        temp = (struct Node*)malloc(1*sizeof(struct Node));
        temp->next = top;
        temp->value = valuePush;
        top = temp;
    }
    numberElements++;
}

void pop (){
    top1 = top;
    if(top1 == NULL){
        printf("Error: Empty stack.\n");
        return;
    }else{
        top1 = top1->next; //point top1 to next node
        printf("Value was popped = %d",top->value);
        free(top);
        top = top1; //after remove 1st node, top jump to next node
        numberElements--;
    }
}

void display(){
    top1= top;
    if(top1 == NULL){
        printf("Stack is empty!\n");
        return;
    }
    while(top1 != NULL){
        printf("\t%d", top1->value);
        top1 = top1->next;
    }
}

void isEmpty(){
    if(top == NULL){
        printf("Stack is empty!\n");
    }else{
        printf("Stack is not empty!\n");
    }
}

void cleanStack(){
    top1 = top;
    while(top1 != NULL){
        top1 = top->next;
        free(top);
        top = top1;
    }
    numberElements = 0;
    // free(top1);
    isEmpty();
    
}