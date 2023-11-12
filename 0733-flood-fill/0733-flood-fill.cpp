class Solution {
private:
    void bfs(int row, int col, int NewColor, int oldColor, vector<vector<int>>& image, vector<vector<int>> & vis){
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        image[row][col] = NewColor;
        vis[row][col] = 1;
        while(!q.empty()){
            int qrow = q.front().first;
            int qcol = q.front().second;
            q.pop();

            int Rrow[] = {-1,0, 1, 0};
            int Ccol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; ++i){
                int nrow = qrow + Rrow[i];
                int ncol = qcol + Ccol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && image[nrow][ncol] == oldColor){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = NewColor;

                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans;
        int oldColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bfs(sr, sc, color, oldColor, image, vis);
        return image;
    }
};