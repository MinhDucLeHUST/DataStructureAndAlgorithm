#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX_STEP 2

struct Node* createNode(int valueNode);
bool isLinkedListCycle(struct Node* head);
struct Node {
    int value;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    // Create cycle linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head->next;
    if (isLinkedListCycle(head)) {
        printf("This is Cycle Linked List!");
    } else {
        printf("This is not Cycle Linked List!");
    }
    return 0;
}
struct Node* createNode(int valueNode) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = valueNode;
    newNode->next = NULL;
    return newNode;
}

bool isLinkedListCycle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct Node* slow = head;
    struct Node* fast = head->next;
    int count = 0;
    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast == slow) {
            return true;
        }
        if (count == MAX_STEP) {
            break;
        }
        slow = slow->next;
    }
    return false;
}