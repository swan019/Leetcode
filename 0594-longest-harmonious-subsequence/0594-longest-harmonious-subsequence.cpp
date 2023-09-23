class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }

        if(mp.size() < 2) return 0;
        int maxi = 0;
        for(auto it : mp){
            int mini = it.first;
            if(mp.find(mini+1) != mp.end()){
                int cnt = mp[mini] + mp[mini+1];
                maxi = max(maxi, cnt); 
            }
        }
        return maxi;;
    }
};