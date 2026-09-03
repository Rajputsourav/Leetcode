/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root,
             struct TreeNode** first,
             struct TreeNode** second,
             struct TreeNode** prev)
{
    if (root == NULL)
        return;

    inorder(root->left, first, second, prev);

    // Detect violation of BST inorder property
    if (*prev != NULL && (*prev)->val > root->val) {
        
        // First wrong node
        if (*first == NULL)
            *first = *prev;

        // Second wrong node
        *second = root;
    }

    *prev = root;

    inorder(root->right, first, second, prev);
}

void recoverTree(struct TreeNode* root)
{
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    struct TreeNode* prev = NULL;

    inorder(root, &first, &second, &prev);

    // Swap the values
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}