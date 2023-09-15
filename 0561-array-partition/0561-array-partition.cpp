class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int MAX_SUM = 0;
        int i = 0;
        while(i < nums.size()-1){
            MAX_SUM += min(nums[i], nums[i+1]);
            i += 2;
        }
        return MAX_SUM;
    }
};