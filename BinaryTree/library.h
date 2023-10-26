#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "stdio.h"
#include "stdlib.h"

struct TreeNode {
    int value;
    struct TreeNode* leftNode;
    struct TreeNode* rightNode;
};

struct TreeNode* createNode(int value);

void printTree(struct TreeNode* root, int spaces) {
    if (root == NULL) {
        return;
    }
    spaces += 5;
    printTree(root->rightNode, spaces);
    printf("\n");
    for (int i = 5; i < spaces; i++) {
        printf(" ");
    }
    printf("%d\n", root->value);

    printTree(root->leftNode, spaces);
}

// don't use
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->leftNode);
        printf("%d ", root->value);
        inorder(root->rightNode);
    }
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

struct TreeNode* createBinarySearchTree() {
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

    root->rightNode->rightNode->rightNode->leftNode = createNode(46);

    return root;
}

#endif