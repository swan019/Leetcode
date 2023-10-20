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
    void help(TreeNode* root, int targetSum,  vector<vector<int>> & ans, vector<int> path, int & sum){
        if(root == NULL) return;

        path.push_back(root->val);
        sum += root->val;
        help(root->left, targetSum, ans, path, sum);
        help(root->right, targetSum, ans, path, sum);

        if(sum == targetSum && root->left == NULL && root->right == NULL){
            ans.push_back(path);
        }
        path.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        int sum = 0;
        help(root, targetSum, ans, path, sum);
        return ans; 
    }
};