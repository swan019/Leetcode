/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentTrack(TreeNode* root, map<TreeNode* , TreeNode*>& mp ){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* tempNode = q.front();
            q.pop();
            if(tempNode -> left != NULL){
                mp[tempNode -> left] = tempNode;
                q.push(tempNode -> left);
            }

            if(tempNode -> right != NULL){
                mp[tempNode -> right] = tempNode;
                q.push(tempNode -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* , TreeNode*> mp;
        parentTrack(root, mp);

        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;
        visited[target] = true;

        q.push(target);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            TreeNode* tempNode;

            if(cnt++ == k){
                break;
            }

            for(int i = 0; i < size; ++i){
                tempNode = q.front();
                q.pop();

                if(tempNode -> left && !visited[tempNode -> left]){
                    q.push(tempNode -> left);
                    visited[tempNode -> left] = true;
                }
                if(tempNode -> right && !visited[tempNode -> right]){
                    q.push(tempNode -> right);
                    visited[tempNode -> right] = true;
                }
                if(mp[tempNode] && !visited[mp[tempNode]]){
                    q.push(mp[tempNode]);
                    visited[mp[tempNode]] = true;
                }

            }
                
        }

        vector<int> ans;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node -> val);
        }

        return ans;
    }
};