class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int, vector<int>> mp;
        for(int i = 0; i < groupSizes.size(); ++i){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto it : mp){
            vector<int> temp;
            int x = it.first;
            int size = it.second.size();
            for(auto itr : it.second){
                if(temp.size() == x){
                    ans.push_back(temp);
                    temp.clear();
                }
                temp.push_back(itr);
            }

            ans.push_back(temp);

        }
        return ans;
    }
};