class Solution {
public:
    pair<int, int> solve(vector<vector<int>>& mat, int row, int col, int i){
        int cnt_1 = 0;
        for(int j = 0; j < col; ++j){
            if(mat[i][j] == 1){
                cnt_1++;
            }else{
                break;
            }
        }

        pair<int, int> ans = {cnt_1, i};
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(); int m = mat[0].size();
        vector<pair<int, int>> cnt_week;
        for(int i = 0; i < n; ++i){
            pair<int, int> ans = solve(mat, n, m, i);
            cnt_week.push_back(ans);
        }
        sort(cnt_week.begin(), cnt_week.end());
        vector<int> arr;
        for(int i = 0; i < k; ++i){
            arr.push_back(cnt_week[i].second);
        }

        for(int i = 0; i < cnt_week.size(); ++i){
            cout << cnt_week[i].first << " " << cnt_week[i].second << endl;
        }
        return arr;
    }
};