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
    void help(TreeNode* root, int & ans){
        if(root == NULL) return;
        if(root->left && (!root->left->left && !root->left->right)){
            ans += root->left->val;
        }
        help(root->left, ans);
        help(root->right, ans);

    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        help(root, ans);
        return ans;
    }
};