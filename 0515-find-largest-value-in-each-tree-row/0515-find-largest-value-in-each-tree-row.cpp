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
    void help(TreeNode* root, vector<int>& ans){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int maxi = INT_MIN;
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode * tempNode = q.front();
                q.pop();

                if(tempNode->left){
                    q.push(tempNode->left);
                }
                if(tempNode->right){
                    q.push(tempNode->right);
                }

                maxi = max(maxi, tempNode->val);
            }

            ans.push_back(maxi);

        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        help(root, ans);
        return ans;
    }
};