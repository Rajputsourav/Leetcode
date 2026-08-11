/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>

int checkHeight(struct TreeNode* node) {
    if (node == NULL) return 0;

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1; 

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1; 

    if (abs(leftHeight - rightHeight) > 1) return -1; 

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}