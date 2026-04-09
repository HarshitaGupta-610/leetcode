class Solution {
private:
int dfs(vector<vector<int>>& grid , int i , int j){
      int n = grid.size();
        int m = grid[0].size();
if( i < 0 || i >= n || j < 0 || j >= m ||grid[i][j] == 0){
    return 0;
}
grid[i][j] = 0;
int area = 1;
area += dfs(grid , i-1 , j);
area += dfs(grid , i+1 , j);
area += dfs(grid , i , j+1);
area += dfs(grid , i , j-1);
return area;

}


public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 1){
                    int curr = dfs(grid , i , j);
                    maxi = max(curr , maxi);
                }
            }
        }
        return maxi;

    }
        
};