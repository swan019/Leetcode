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
    void preOrder(TreeNode* root, vector<string>&ans, vector<int>&arr){
        arr.push_back(root->val);
        if(!root->left && !root->right){
            string s = "";
            for(int i = 0; i < arr.size(); ++i){
                s += to_string(arr[i]);
                if(i != arr.size()-1){
                    s += "->";
                }
            }
            ans.push_back(s);
        }


        if(root->left){
            preOrder(root->left, ans, arr);
        }
        if(root->right){
            preOrder(root->right, ans, arr);
        }
        arr.pop_back();

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        vector<int> arr;
        preOrder(root, ans, arr);
        return ans;
    }
};