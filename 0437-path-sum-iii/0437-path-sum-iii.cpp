// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// private:
//     void help(TreeNode* root, int targetSum,  int &count, vector<int> path){
//         if(root == NULL) return;

//         path.push_back(root->val);
//         help(root->left, targetSum, count, path);
//         help(root->right, targetSum, count, path);

//         int size = path.size();
//         long long sum = 0;
//         for(int i = size-1; i >= 0; i--){
//             sum += path[i];

//             if(sum == targetSum){
//                 count++;
//             }
//         }

//         path.pop_back();
//     }
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         vector<int> path;
//         int count = 0;
//         help(root, targetSum, count, path);
//         return count;
//     }
// };

class Solution {
public:
    #define ll long long
    map<ll ,int> mp;
    int ans=0;
    void solve(TreeNode* root, int targetSum,ll currSum){
        if(root==NULL) return;
        currSum+=root->val;
        ans+=mp[currSum-targetSum];//it mean between the ongoing process there is a place where targetSum is generated.
        mp[currSum]++;
        solve(root->left , targetSum,currSum);
        solve(root->right , targetSum,currSum);
        mp[currSum]--;
        currSum-=root->val;

    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]++;
        ll currSum=0;
        solve(root,targetSum,currSum);
        return ans;
    }
};