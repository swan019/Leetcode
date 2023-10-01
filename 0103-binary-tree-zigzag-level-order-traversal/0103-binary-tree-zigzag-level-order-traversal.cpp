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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool l_to_r = true;
        while(!q.empty()){
            int size = q.size();
            TreeNode* temp;
            vector<int> ans(size);
            for(int i = 0; i < size; ++i){
                temp = q.front();
                q.pop();
                int index = l_to_r ? i : size - i - 1;
                ans[index] = temp->val;

                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            result.push_back(ans);
            l_to_r = !l_to_r;
        }

        return result;
    }
};