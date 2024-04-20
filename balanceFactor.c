#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to calculate the height of a tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the balance factor for every node
void findBalanceFactor(struct Node* root) {
    if (root == NULL) {
        return;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int balanceFactor = leftHeight - rightHeight;

    printf("Node %d has balance factor %d\n", root->data, balanceFactor);

    findBalanceFactor(root->left);
    findBalanceFactor(root->right);
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 18);

    printf("Balance factors for each node in the binary search tree:\n");
    findBalanceFactor(root);

    return 0;
}
