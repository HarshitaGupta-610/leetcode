class Solution {
public:

void dfs(vector<vector<int>>&image , int i , int j , int oldc , int newc){
     int n = image.size();
 int m = image[0].size();
 if( i < 0 || i >= n || j <0 || j >= m || image[i][j] != oldc) return;
 image[i][j] = newc;    
 dfs(image , i-1,j,oldc,newc);//up
 dfs(image , i+1,j,oldc,newc);//down
 dfs(image , i,j-1,oldc,newc);//left
 dfs(image , i,j+1,oldc,newc);//right
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
   int oldc = image[sr][sc];
   if(oldc == color) return image;
   else dfs(image,sr,sc,oldc,color);
   return image;
    }
};