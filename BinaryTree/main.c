#include "library.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

struct TreeNode* insertNode(struct TreeNode* root, int valueInsert);
void insertNodeUsingLoop(struct TreeNode* tempNode, int valueInsert);
void insertNodeUsignRecursive(struct TreeNode* root, int valueInsert);
struct TreeNode* removeNode(struct TreeNode* root, int valueRemove);
struct TreeNode* findMostLeftNode(struct TreeNode* root);
struct TreeNode* findMostRightNode(struct TreeNode* root);
struct TreeNode* findNode(struct TreeNode* root, int findValue);
struct TreeNode* postOrderTraversal(struct TreeNode* root);
struct TreeNode* inOrderTraversal(struct TreeNode* root);
struct TreeNode* preOrderTraversal(struct TreeNode* root);
int findDepthTree(struct TreeNode* root);
int calculateSumOfTree(struct TreeNode* root);
bool isPathReturnCorrectSum(struct TreeNode* root, int currentSum, int desiredValue);
bool isNodeLeaf(struct TreeNode* root);

int main() {
    struct TreeNode* root = createBinarySearchTree();
    if (isPathReturnCorrectSum(root, 0, 60)) {
        printf("Ok!\n");
    } else {
        printf("Fail!\n");
    }
    // printTree(root, 0);
    return 0;
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

// Traversal
struct TreeNode* preOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return NULL;

    printf("%d ", root->value);
    preOrderTraversal(root->leftNode);
    preOrderTraversal(root->rightNode);

    return root;
}

struct TreeNode* inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return NULL;
    inOrderTraversal(root->leftNode);
    printf("%d ", root->value);
    inOrderTraversal(root->rightNode);
    return root;
}

struct TreeNode* postOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return NULL;
    postOrderTraversal(root->leftNode);
    postOrderTraversal(root->rightNode);
    printf("%d ", root->value);
    return root;
}

// Calculate the height of a binary tree

int findDepthTree(struct TreeNode* root) {
    int depth = 0;
    if (root == NULL) return 0;
    int depthLeftNode = findDepthTree(root->leftNode);
    int depthRightNode = findDepthTree(root->rightNode);
    if (depthLeftNode > depthRightNode) {
        return depthLeftNode + 1;
    } else {
        return depthRightNode + 1;
    }
}

// Sum
int calculateSumOfTree(struct TreeNode* root) {
    if (root == NULL) return 0;
    int sumResult = root->value;
    sumResult += calculateSumOfTree(root->leftNode);
    sumResult += calculateSumOfTree(root->rightNode);
    return sumResult;
}

/*
    Find path of sum:
        + isNodeLeaf() là hàm check Node có phải node lá hay không, đây là node có node trái & phải == NULL.
        Hay nói cách khác là check xem node này có phải node dưới cùng của 1 path hay không.
        + isPathReturnCorrectSum() là hàm check xem có đường dẫn trên tree có tổng bằng giá trị mong muốn.
            @param: currentSum là tổng của 1 đường dẫn trong cây
                    desiredValue là giá trị mong muốn
*/

bool isNodeLeaf(struct TreeNode* root) {
    return root->leftNode == NULL && root->rightNode == NULL;
}

bool isPathReturnCorrectSum(struct TreeNode* root, int currentSum, int desiredValue) {
    if (root == NULL) return false;
    currentSum += root->value;
    if (isNodeLeaf(root)) {
        return currentSum == desiredValue;
    }
    bool resultNodeLeft = isPathReturnCorrectSum(root->leftNode, currentSum, desiredValue);
    bool resultNodeRight = isPathReturnCorrectSum(root->rightNode, currentSum, desiredValue);

    return resultNodeLeft || resultNodeRight;
}
