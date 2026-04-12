class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        int original = image[sr][sc];
        if (original == color) return image;  
        
        queue<pair<int,int>> q;
        q.push({sr, sc});
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            
            image[i][j] = color;
            
           
            int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            
            for (auto& d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                
               
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                   
                    if (image[ni][nj] == original) {
                        q.push({ni, nj});
                    }
                }
            }
        }
        
        return image;
    }
};
