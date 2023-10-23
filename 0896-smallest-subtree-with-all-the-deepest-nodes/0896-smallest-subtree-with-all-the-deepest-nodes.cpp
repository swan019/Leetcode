
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
    void levelOrder(TreeNode* root, vector<vector<int>>& ans){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp;
            int n = q.size();
            vector<int> arr;
            for(int i = 0; i < n; ++i){
                temp = q.front();
                q.pop();
                arr.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            ans.push_back(arr);
        }
    }

    TreeNode* Travers(TreeNode* root, int node){
        if(root == NULL){
            return NULL;
        }

        if(root->val == node){
            return root;
        }

        TreeNode* lh = Travers(root->left, node);
        TreeNode* rh = Travers(root->right, node);

        if(lh != NULL && rh == NULL){
            return lh;
        }

        if(lh == NULL && rh != NULL){
            return rh;
        }

        return NULL;
    }

    TreeNode*  lowest_common_ancestor(TreeNode* root, int p, int q){
        if(root == NULL){
            return NULL;
        }

        if(root->val == p || root->val == q){
            return root;
        }

        TreeNode* lh = lowest_common_ancestor(root->left, p, q);
        TreeNode* rh = lowest_common_ancestor(root->right, p, q);

        if(lh != NULL && rh != NULL){
            return root;
        }else if(lh != NULL && rh == NULL){
            return lh;
        }else if(lh == NULL && rh != NULL){
            return rh;
        }

        return NULL;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return NULL;
        vector<vector<int>> ans;
        levelOrder(root, ans);
        int size = ans.size();
        vector<int> Depth_Nodes = ans[ans.size()-1];
        if(Depth_Nodes.size() == 1){
            return Travers(root, Depth_Nodes[0]);
        }
        int n = Depth_Nodes.size();

        return lowest_common_ancestor(root, Depth_Nodes[0], Depth_Nodes[n-1]);
    }
};