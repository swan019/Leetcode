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
    void solve(TreeNode* &root,int tar){
        if(!root) return;

        solve(root->left,tar);
        solve(root->right,tar);

        if(!root->left && !root->right && root->val == tar){
            root = NULL;
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root,target);
        return root;
    }
};