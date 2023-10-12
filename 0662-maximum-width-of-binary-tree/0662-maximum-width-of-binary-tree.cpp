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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int left, right;
            int mini = q.front().second;
            
            for(int i = 0; i < size; ++i){
                TreeNode* tempNode = q.front().first;
                long long curr = q.front().second - mini;
                q.pop();

                if(i == 0){
                    left = curr;
                }

                if(i == size - 1){
                    right = curr;
                }

                if(tempNode -> left){
                    q.push({tempNode -> left, 2*curr+1});
                }

                if(tempNode -> right){
                    q.push({tempNode -> right, 2*curr+2});
                }
                
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};