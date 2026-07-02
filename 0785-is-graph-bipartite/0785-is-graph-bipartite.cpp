class Solution {
public:

    bool dfs(int node , int clr , vector<vector<int>>& graph , vector<int>& colour){
colour[node] =clr; // jo abhi current node hai usko colour assign kardo
for(int neighbour : graph[node]){
    if(colour[neighbour] == -1){//abhi is node ko koi colour assign nahi hua
        if(!dfs(neighbour , 1 - clr , graph , colour)){
            // agar recursion ne kaha graphs bipartite nahin hain toh imeediately humein false return karna hai
            return false;
        }
    }
else if(colour[neighbour] == clr){
    //padosi ka colour same hai toh obv biparitie nahi hai
    return false;
}
}
return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colour(n,-1);

        for(int i = 0 ; i < n ; i++){
            if(colour[i] == -1){
                if(!dfs(i,0,graph,colour)){
                    return false;
                }
            }
        }


    
        return true;
    }
};