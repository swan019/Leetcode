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
    int help(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int leftmaxsum = max(0, help(root->left, maxi));
        int rightmaxsum = max(0, help(root->right, maxi));
        int val = root->val;
        maxi = max(maxi, val+leftmaxsum+rightmaxsum);
        return max(leftmaxsum, rightmaxsum)+val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int x = help(root, maxi);
        return maxi;
    }
};