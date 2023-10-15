#ifndef __LIB_SORT_H
#define __LIB_SORT_H

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

#endif