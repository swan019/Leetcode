class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left(nums.size(),0), right(nums.size(),0);
        left[0] = 0;
        int n = nums.size();
        right[n-1] = 0;
        for(int i = 1; i < n; ++i){
            left[i] = left[i-1] + nums[i-1];
        }

        for(int i = n-2; i >= 0; --i){
            right[i] = right[i+1] + nums[i+1];
        }

        for(int i = 0; i < n; ++i){
            nums[i] = abs(left[i] - right[i]);
        }

        return nums;

    }
};