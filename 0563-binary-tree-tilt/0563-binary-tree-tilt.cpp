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
private:
    int help(TreeNode* root, int sum){
        if(root == NULL){
            return 0;
        }

        int lh = help(root->left, sum);
        int rh = help(root->right, sum);

        int x = root->val;
        root->val = abs(lh-rh);
        return (lh+rh) + x;

    }
    void trav(TreeNode* root, int & ans){
        if(root == NULL) return;
        ans += root->val;
        trav(root->left, ans);
        trav(root->right, ans);
    }
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        int x =  help(root, sum);
        int ans = 0;
        trav(root, ans);
        return ans;
    }
};