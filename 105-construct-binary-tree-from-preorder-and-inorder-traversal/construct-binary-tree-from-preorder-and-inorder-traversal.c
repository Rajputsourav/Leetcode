/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {
    
    if (preorderSize == 0)
        return NULL;

    int rootValue = preorder[0];

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = rootValue;
    root->left = NULL;
    root->right = NULL;

    int index = 0;
    while (inorder[index] != rootValue)
        index++;

    int leftSize = index;

    root->left = buildTree(
        preorder + 1,
        leftSize,
        inorder,
        leftSize
    );

    root->right = buildTree(
        preorder + leftSize + 1,
        preorderSize - leftSize - 1,
        inorder + leftSize + 1,
        inorderSize - leftSize - 1
    );

    return root;
}