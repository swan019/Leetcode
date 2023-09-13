class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n < 2) return n;
        int ans = 0;
        vector<int> vec(n, 1);

        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                vec[i] = vec[i-1]+1;
            }
        }
        if(ratings[n-2] > ratings[n-1] && (vec[n-2] == vec[n-1] || vec[n-3] == vec[n-2])){
            vec[n-2]++;
        }

        for(int i = n-1; i > 0; i--){
            if(ratings[i-1]>ratings[i])
			 vec[i-1]=max(vec[i]+1,vec[i-1]);
        }

        for(int i = 0; i < vec.size(); ++i){
            ans += vec[i];
        }

        return ans;
    }
};