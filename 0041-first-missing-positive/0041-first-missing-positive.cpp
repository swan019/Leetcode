class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        int maxi = -1;

        for(auto it : nums){
            st.insert(it);
            maxi = max(it, maxi);
        }

        int ans = -1;
        int i;
        for(i = 1; i <= maxi; i++){
            if(st.find(i) == st.end()){
                ans = i;
                return ans;
            }
        }

        return i;

    }
};