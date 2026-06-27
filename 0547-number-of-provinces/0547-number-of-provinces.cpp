class Solution {
public:

void dfs(int node , vector<vector<int>>& isConnected , vector<int>&visited){
   visited[node] = 1;
   for(int neigh = 0 ; neigh < isConnected.size() ; neigh++){
           if(isConnected[node][neigh] == 1 && !visited[neigh]){
            dfs(neigh,isConnected , visited);
           }
   }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i] ){
                ans++;
            }
            dfs(i ,isConnected ,visited);
        }
        return ans;
    }
};