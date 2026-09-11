class Solution {
public:
    int res = 0;
    void bfs(vector<vector<int>>& grid, int n, int m,
        queue<pair<int, int>>& q) {
        int i, j;
        while (!q.empty()) {
            int sz = q.size();
             while (sz--) {
                i = q.front().first;
                j = q.front().second;
                q.pop();
                if ((i + 1 < n) && grid[i+1][j]==1) {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if ((j + 1 < m)&& grid[i][j+1]==1) {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                if ((i - 1 >= 0)&&grid[i-1][j]==1) {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if (j - 1 >= 0 && grid[i][j-1]==1) {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
            }
            if(!q.empty()){
            res++;
            }
        }
    }
      int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        bfs(grid, n, m, q);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] ==1) {
                    return -1;
                   
                }
            }
        }
        return res;
    }
};