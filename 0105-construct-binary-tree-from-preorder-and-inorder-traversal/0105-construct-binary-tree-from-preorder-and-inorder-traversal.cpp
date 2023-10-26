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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd, int & n ,unordered_map<int,int> &map){
        //base
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position =  map[element];
        //recursive calls
        root -> left = solve(preorder, inorder, index, inorderStart, position-1, n,map);
        root -> right = solve(preorder, inorder, index, position+1, inorderEnd, n, map);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIndex = 0;
        unordered_map<int,int> mapping;
        createMap(inorder,mapping,n);
        TreeNode* ans = solve(preorder, inorder, preIndex, 0, n-1, n, mapping);
        return ans;
    }
};
