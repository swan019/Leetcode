class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for(auto it : nums){
            if(it%2 == 0){
                mp[it]++;
            }
        }

        if(mp.size() < 1){
            return -1;
        }

        int maxi = -1;
        int maxiNo = 0;
        for(auto it : mp){
            if(maxi < it.second){
                maxiNo = it.first;
                maxi = it.second;
            }
        }

        return maxiNo;
    }
};