#include <stdio.h>
#include <stdlib.h>

// Structure for a node of binary tree
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate height of a binary tree
int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to calculate diameter of a binary tree
int diameter(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int rootDiameter = height(root->left) + height(root->right) + 1;
    return max(rootDiameter, max(leftDiameter, rightDiameter));
}

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Example usage
int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(8);

    printf("Diameter of the binary tree: %d\n", diameter(root));
    return 0;
}