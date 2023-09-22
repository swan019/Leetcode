class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        long long sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            int rem = (sum % k + k) % k;
            cnt += hash[rem];
            hash[rem]++;
        }

        return cnt;
    }
};