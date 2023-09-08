class Solution {
vector<int> genarateRow(int n){
    vector<int> temp;
    int ans = 1;
    temp.push_back(1);
    for(int i =1; i < n; ++i){
        ans = ans * (n-i);
        ans /= i;
        temp.push_back(ans);
    }

    return temp;
}
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; ++i){
            vector<int> temp = genarateRow(i);
            ans.push_back(temp);
        }

        return ans;
    }
};