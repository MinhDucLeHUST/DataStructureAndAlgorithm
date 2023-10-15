#include "../library/libBinaryTree.h"
#include "stdio.h"
#include "stdlib.h"

struct TreeNode* createNode(int value);

int main() {
    struct TreeNode* root = createNode(10);
    root->leftNode = createNode(8);
    root->rightNode = createNode(11);

    root->leftNode->leftNode = createNode(6);
    root->leftNode->rightNode = createNode(9);

    root->rightNode->leftNode = createNode(10);
    root->rightNode->rightNode = createNode(16);

    root->rightNode->leftNode->rightNode = createNode(12);

    printTree(root, 0);
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
