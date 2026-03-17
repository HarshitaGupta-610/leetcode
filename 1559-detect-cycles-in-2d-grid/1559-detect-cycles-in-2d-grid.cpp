class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        function<bool(int,int,int,int)> dfs;

        dfs = [&](int x, int y, int px, int py) {
            visited[x][y] = true;

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
                    if (dfs(nx, ny, x, y)){
                        return true;
                    }
                }
             
                else if (nx != px || ny != py) {
                    return true;
                }
            }

            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};