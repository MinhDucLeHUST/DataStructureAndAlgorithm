#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX_STEP 2

struct Node* createNode(int valueNode);
struct Node* findStartCycle(struct Node* head);

struct Node {
    int value;
    struct Node* next;
};
// bool isCycle = false;

bool detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    // bool isCycle = false;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = head->next;
        fast = head->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    struct Node* head = createNode(1);
    struct Node* current = head;

    for (int i = 2; i < 6; i++) {
        struct Node* newNode = createNode(i);
        current->next = newNode;
        current = newNode;
    }
    current->next = head;
    current = head;
    if (detectLoop(head)) {
        printf("Cycle");
    } else {
        printf("Not cycle");
    }
    do {
        printf("%d -> ", current->value);
        current = current->next;
    } while (current != head);

    return 0;
}
struct Node* createNode(int valueNode) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = valueNode;
    newNode->next = NULL;  // final node point to null
    return newNode;
}

struct Node* findStartCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    bool isCycle = false;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = head->next;
        fast = head->next->next;
        if (slow == fast) {
            isCycle = true;
            break;
        }
    }
    if (isCycle) {
        printf("This is cycle linked list!");
        fast = head;
        while (fast != NULL && slow != NULL) {
            if (fast == slow) {
                return fast;
            }
            fast = fast->next;
            slow = slow->next;
        }
    }
    return NULL;
}
