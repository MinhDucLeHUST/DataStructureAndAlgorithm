#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

struct Tree {
    struct TreeNode* root;
};

int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

int getCol(int h) {
    if (h == 1)
        return 1;
    return getCol(h - 1) + getCol(h - 1) + 1;
}

void printTree(int** M, struct TreeNode* root, int col, int row, int height) {
    if (root == NULL)
        return;
    M[row][col] = root->data;
    printTree(M, root->left, col - (int)pow(2, height - 2), row + 1, height - 1);
    printTree(M, root->right, col + (int)pow(2, height - 2), row + 1, height - 1);
}

void treePrinter(struct Tree tree) {
    int h = height(tree.root);
    int col = getCol(h);
    int** M = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        M[i] = (int*)malloc(col * sizeof(int));
    }
    printTree(M, tree.root, col / 2, 0, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < col; j++) {
            if (M[i][j] == 0)
                printf("  ");
            else
                printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < h; i++) {
        free(M[i]);
    }
    free(M);
}

int main() {
    struct Tree myTree;
    myTree.root = createNode(1);
    myTree.root->left = createNode(2);
    myTree.root->right = createNode(3);
    myTree.root->left->left = createNode(4);
    myTree.root->left->right = createNode(5);
    myTree.root->right->left = createNode(6);
    myTree.root->right->right = createNode(7);
    treePrinter(myTree);
    return 0;
}
