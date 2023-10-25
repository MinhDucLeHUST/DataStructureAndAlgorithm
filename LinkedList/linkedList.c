#include "stdio.h"
#include "stdlib.h"

struct Node{
    int value;
    struct Node * next;
};

int main(){
    return 0;
}

struct Node * createNewNode(int valueOfNode){
    struct Node * newNode  = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Failed to use malloc");
        exit(1);
    }
    newNode->value = valueOfNode;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node ** head, int valueOfNode){
    struct Node * newNode = createNewNode(valueOfNode);
    if(*head == NULL){
        *head = newNode;
    }else{
        struct Node* current = *head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void addNodeToTail(){

}

void addNodeToMid(){

}

void displayList (struct Node * head){
    struct Node * current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}