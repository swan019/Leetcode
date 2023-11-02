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
    void solve(TreeNode* root,  map<TreeNode* , pair<int, int>> & mp, int & cnt){
        if(root == NULL){
            return;
        }
        if(!root->left && !root->right){
            mp[root] = {root->val, 1};
        }
        solve(root->left, mp, cnt);
        solve(root->right, mp, cnt);
        

        if(root -> left && root -> right){
            mp[root] = {root->val + mp[root->left].first + mp[root->right].first , 1 + mp[root->left].second + mp[root->right].second};
        }else if(root -> right != NULL && root -> left == NULL){
            mp[root] = {root->val +  mp[root->right].first , 1 +  mp[root->right].second};
        }else if(root -> left != NULL && root -> right == NULL){
            mp[root] = {root->val +  mp[root->left].first , 1 +  mp[root->left].second};
        }

        if(mp[root].first/mp[root].second == root->val){
            cnt++;
        }
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root->left && !root -> right){
            return 1;
        }
        map<TreeNode* , pair<int, int>> mp;
        int cnt = 0;
        solve(root, mp, cnt); 
        return cnt;
    }
};