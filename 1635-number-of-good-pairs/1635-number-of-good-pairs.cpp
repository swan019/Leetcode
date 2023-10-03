class Solution {
int combination(int n){
    return n*(n-1)/2;
}
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<bool> cheak(100, 0);
        vector<vector<int>> ans;
        int n = nums.size(); 
        for(int i = 0; i < n; ++i){
            vector<int> temp;
            if(!cheak[nums[i]])
            {
                temp.push_back(nums[i]);
                for(int j = i+1; j < n; ++j){
                    if(nums[i] == nums[j])
                    {
                        temp.push_back(j);
                    }
                }
            }
                cheak[nums[i]] = 1;
                ans.push_back(temp);
                temp.clear();
        }

        int k = 0;
        int sz = ans.size();
        for(int i = 0; i < sz; ++i){
            k = k + combination(ans[i].size());
        }

        return k;

    }
};