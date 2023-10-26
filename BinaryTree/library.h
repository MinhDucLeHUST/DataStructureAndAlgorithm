#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "stdio.h"
#include "stdlib.h"

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