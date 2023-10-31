class Solution {
public:
    // x ^ y = z 
    // but we dont know value of y only know x & z;
    // then 
    // y = (x ^ z) ^ x
    // pref[i-1] ^ ans[i] = pref[i];
    int find_y(int x, int z) {
        return x ^ z ^ x;
    }

    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            if(i != 0){
                ans[i] = pref[i]^pref[i-1];
            }else{
                ans[i] = pref[i]; 
            }
        }

        return ans;
    }
};