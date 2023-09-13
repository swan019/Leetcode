class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            int pos = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            ans[i] = pos;
        }
        return ans;
    }
};