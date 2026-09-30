/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long ans = LLONG_MAX;

    void dfs(TreeNode* root, int minValue) {
        if (root == NULL)
            return;

        // Found a value greater than minimum
        if (root->val > minValue) {
            ans = min(ans, (long long)root->val);
            return;  // No need to explore this subtree
        }

        dfs(root->left, minValue);
        dfs(root->right, minValue);
    }

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root, root->val);

        if (ans == LLONG_MAX)
            return -1;

        return (int)ans;
    }
};