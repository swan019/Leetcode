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
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        while(!q.empty()){
           TreeNode* temp;
            int n = q.size();
            vector<int> kamapurta(n);

            for(int i = 0; i < n; ++i){
                temp = q.front();
                q.pop();
                int index =left_to_right ? i : n - i - 1;
                kamapurta[index] = temp->val;
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }

            }

            ans.push_back(kamapurta);
            left_to_right = !left_to_right;
        }

        return ans;
    }
};