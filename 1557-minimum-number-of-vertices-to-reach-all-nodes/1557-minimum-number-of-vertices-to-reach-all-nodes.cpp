class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;//to store the nodes
        vector<int>seen(n,0);
        for(auto &it : edges){
            seen[it[1]] = 1;   // connected node ko mark        
        }
        for(int i = 0 ; i < n ; i++){
            if(seen[i] == 0){// jo kahin se visit nahi hui 
                ans.push_back(i);
            }
        }

return ans;
    }
};