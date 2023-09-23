class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        map<vector<int> , int> mp;
        int n = matrix.size();
        int sum = 0;
        map<int, int> mp2;
        for(int i = 0; i < 1; ++i){
            for(int j = 0; j < n; ++j){
                mp2[matrix[i][j]]++;
            }
        }

        if(mp2.size() != n) return false;
        

        for(auto it : matrix){
            vector<int> temp = it;
            sort(temp.begin(), temp.end());
            if(temp[0] != 1 || temp[n-1] != n){
                return false;
            }
            mp[temp]++;
        }

        if(mp.size() >= 2) return false;

        for(int i = 0; i < n; ++i){
            vector<int> temp;
            for(int j = 0; j < n; ++j){
                temp.push_back(matrix[j][i]);
            }
            sort(temp.begin(), temp.end());
            mp[temp]++;
        }

        if(mp.size() >= 2) return false;
        return true;
    }
};