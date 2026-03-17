class Solution {
public:

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int x, int y, int px, int py, int m, int n) {

        visited[x][y] = true;

        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for (auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n){
                continue;
            }

            if (grid[nx][ny] != grid[x][y]){
                continue;
            }

            if (!visited[nx][ny]) {
                if (dfs(grid, visited, nx, ny, x, y, m, n))
                    return true;
            }
          
            else if (nx != px || ny != py) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, m, n))
                        return true;
                }

            }
        }

        return false;
    }
};