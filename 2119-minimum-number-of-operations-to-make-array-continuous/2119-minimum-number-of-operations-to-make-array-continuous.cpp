class Solution {
public:
    int minOperations(vector<int>& nums) {
        int length = nums.size();
        int ans = length;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int right = 0;

        for (int left = 0; left < nums.size(); left++) {
            while (right < nums.size() && nums[right] < nums[left] + length) {
                right++;
            }

            ans = min(ans, length - (right - left));
        }

        return ans;        
    }
};