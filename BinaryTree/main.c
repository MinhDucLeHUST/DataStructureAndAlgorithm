#include "library.h"
#include "stdio.h"
#include "stdlib.h"

struct TreeNode* createNode(int value);
struct TreeNode* insertNode(struct TreeNode* root, int valueInsert);
void insertNodeUsingLoop(struct TreeNode* tempNode, int valueInsert);
void insertNodeUsignRecursive(struct TreeNode* root, int valueInsert);
struct TreeNode* removeNode(struct TreeNode* root, int valueRemove);
struct TreeNode* findMostLeftNode(struct TreeNode* root);
struct TreeNode* findMostRightNode(struct TreeNode* root);
struct TreeNode* findNode(struct TreeNode* root, int findValue);

int main() {
    struct TreeNode* root = createNode(25);
    root->leftNode = createNode(20);
    root->rightNode = createNode(36);

    root->leftNode->leftNode = createNode(10);
    root->leftNode->rightNode = createNode(22);

    root->rightNode->leftNode = createNode(30);
    root->rightNode->rightNode = createNode(40);

    root->leftNode->leftNode->leftNode = createNode(5);
    root->leftNode->leftNode->rightNode = createNode(12);

    root->rightNode->leftNode->leftNode = createNode(28);

    root->rightNode->rightNode->leftNode = createNode(38);
    root->rightNode->rightNode->rightNode = createNode(48);
    // insertNode(root, 19);
    // root = removeNode(root, 36);
    root = findNode(root, 5);
    printTree(root, 0);
    // inorder(root);
    return 0;
}

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode) {
        newNode->value = value;
        newNode->leftNode = NULL;
        newNode->rightNode = NULL;
    }
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int valueInsert) {
    if (root == NULL) {
        return createNode(valueInsert);
    }
    // 2 ways to insert a node
    else {
        // insertNodeUsingLoop(root, valueInsert);
        insertNodeUsignRecursive(root, valueInsert);
        return root;
    }
}
// using loop to insert node
void insertNodeUsingLoop(struct TreeNode* root, int valueInsert) {
    struct TreeNode* tempNode = root;
    while (1) {
        if (tempNode->value > valueInsert) {
            printf("< value insert\n");
            if (tempNode->leftNode == NULL) {
                tempNode->leftNode = createNode(valueInsert);
                break;
            } else {
                tempNode = tempNode->leftNode;
            }
        } else {
            printf(">= value insert\n");
            if (tempNode->rightNode == NULL) {
                tempNode->rightNode = createNode(valueInsert);
                printf("node is null \n");
                break;
            } else {
                tempNode = tempNode->rightNode;
            }
        }
    }
}

// using recursive to insert node
void insertNodeUsignRecursive(struct TreeNode* root, int valueInsert) {
    if (root->value > valueInsert) {
        if (root->leftNode == NULL) {
            root->leftNode = createNode(valueInsert);
        } else {
            insertNode(root->leftNode, valueInsert);
        }
    } else {
        if (root->rightNode == NULL) {
            root->rightNode = createNode(valueInsert);
        } else {
            insertNode(root->rightNode, valueInsert);
        }
    }
}

struct TreeNode* removeNode(struct TreeNode* root, int valueRemove) {
    if (root == NULL) return NULL;
    if (valueRemove < root->value) {
        root->leftNode = removeNode(root->leftNode, valueRemove);
    } else if (valueRemove > root->value) {
        root->rightNode = removeNode(root->rightNode, valueRemove);
    } else {
        if (root->leftNode == NULL && root->rightNode == NULL) {
            return NULL;
        } else if (root->leftNode != NULL && root->rightNode == NULL) {
            free(root);
            return root->leftNode;
        } else if (root->leftNode == NULL && root->rightNode != NULL) {
            printf("left = null, right = %d\n", root->rightNode->value);
            free(root);
            return root->rightNode;
        } else {
            struct TreeNode* mostLeftNode = findMostLeftNode(root->rightNode);
            root->value = mostLeftNode->value;
            root->rightNode = removeNode(root->rightNode, mostLeftNode->value);
        }
    }
    return root;
}

struct TreeNode* findMostLeftNode(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode* mostLeftNode = root;
    while (mostLeftNode->leftNode != NULL) {
        mostLeftNode = mostLeftNode->leftNode;
    }
    return mostLeftNode;
}

struct TreeNode* findMostRightNode(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode* mostRightNode = root;
    while (mostRightNode->rightNode != NULL) {
        mostRightNode = mostRightNode->rightNode;
    }
    return mostRightNode;
}

struct TreeNode* findNode(struct TreeNode* root, int findValue) {
    if (root == NULL) return NULL;
    if (findValue < root->value) {
        root->leftNode = findNode(root->leftNode, findValue);
    } else if (findValue > root->value) {
        root->rightNode = findNode(root->rightNode, findValue);
    } else {
        printf("value = %d", root->value);
        return root;
    }
}