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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> mp;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            mp[p.second].push_back(p.first->val);
            if(p.first->left){
                q.push({p.first->left, p.second+1});
            }
            if(p.first->right){
                q.push({p.first->right, p.second+1});
            }
        }

        
        vector<int> arr = mp[mp.size()-1];
        int sum = 0;
        for(auto it : arr){
            sum += it;
        }

        return sum;

    }
};