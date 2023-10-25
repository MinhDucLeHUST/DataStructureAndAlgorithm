#ifndef __LIB_BST_H
#define __LIB_BST_H

#include "stdio.h"
#include "stdlib.h"

// struct TreeNode* createNode(int value);
// struct TreeNode* insertNode(struct TreeNode* root, int valueInsert);
// void insertNodeUsingLoop(struct TreeNode* tempNode, int valueInsert);
// void insertNodeUsignRecursive(struct TreeNode* root, int valueInsert);
// struct TreeNode* findMostLeftNode(struct TreeNode* root);
// struct TreeNode* findMostRightNode(struct TreeNode* root);

struct TreeNode {
    int value;
    struct TreeNode* leftNode;
    struct TreeNode* rightNode;
};

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

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->leftNode);
        printf("%d ", root->value);
        inorder(root->rightNode);
    }
}

#endif