class Solution {
public:
    int dfs(int n, int k, int rootVal){
        if(n == 1){
            return rootVal;
        }
        int totalNode = pow(2,n-1);

        // target node present in right subTree
        if(k > (totalNode / 2)){
            int nextRoot_val = (rootVal == 0) ? 1 : 0;
            int TargetNewPos = k - (totalNode / 2);
            return dfs(n-1, TargetNewPos, nextRoot_val);
        }
        // otherwise target node is in left subtree  
        else{
            int nextRoot_val = (rootVal == 0) ? 0 : 1;
            return dfs(n-1, k, nextRoot_val);
        }
    }

    int kthGrammar(int n, int k) {
        int ans = dfs(n, k, 0);
        return ans;
    }
};