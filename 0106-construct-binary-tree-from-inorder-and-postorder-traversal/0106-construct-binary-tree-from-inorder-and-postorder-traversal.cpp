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
    void createMap(vector<int> &in, unordered_map<int,int> &map, int &n){
        for(int i=0; i<n; i++){
            map[in[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd, int & n ,unordered_map<int,int> &map){
        //base
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position =  map[element];
        //recursive calls
        root -> right = solve(postorder, inorder, index, position+1, inorderEnd, n, map);
        root -> left = solve(postorder, inorder, index, inorderStart, position-1, n,map);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int preIndex = n-1;
        unordered_map<int,int> mapping;
        createMap(inorder,mapping,n);
        TreeNode* ans = solve(postorder, inorder, preIndex, 0, n-1, n, mapping);
        return ans;
    }
};