class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(auto it : intervals){
            if(ans.size() == 0){
                ans.push_back(it);
            }else{
                // (1,4) (2,6)

                if(ans.back()[1] >= it[0] && ans.back()[1] <= it[1]){
                    ans.back()[1] = it[1];
                }else if(ans.back()[1] >= it[0] && ans.back()[1] >= it[1] ){
                    // ans.back()[1] = 
                }else{
                    ans.push_back(it);
                }

                // (1,4) (2,3)
            }
        }

        return ans;
    }
};