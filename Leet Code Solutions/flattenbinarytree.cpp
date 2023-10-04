#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if (!root) {
        return;
    }

    // Store the right subtree
    TreeNode* rightSubtree = root->right;

    // Flatten the left subtree
    flatten(root->left);

    // Attach the flattened left subtree to the right
    root->right = root->left;
    root->left = NULL;

    // Find the end of the current flattened tree (the rightmost node)
    TreeNode* current = root;
    while (current->right) {
        current = current->right;
    }

    // Attach the original right subtree to the right of the current flattened tree
    current->right = rightSubtree;

    // Flatten the original right subtree
    flatten(rightSubtree);
}

// Helper function to print the flattened tree
void printFlattenedTree(TreeNode* root) {
    while (root) {
