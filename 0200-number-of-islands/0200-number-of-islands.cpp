class Solution {
private:
    void bfs(int rrow, int ccol, vector<vector<bool>> & vis, vector<vector<char>>& grid){
        int n = grid.size(); int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({rrow, ccol});
        vis[rrow][ccol] = true;
        int delr[4] = {-1, 0,1,0};
        int delc[4] = {0,1, 0,-1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; ++i){
                int nrow = row + delr[i] ;
                int ncol = col + delc[i] ;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};