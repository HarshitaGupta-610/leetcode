class Solution {
public:

void dfs(int room , vector<vector<int>>& rooms , vector<int>&vis){//normal dfs
    vis[room] = 1;
    for(auto it : rooms[room]){//room ke andar keys
        if(!vis[it]){
            dfs(it,rooms,vis);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();//finding total rooms
  vector<int>vis(n,0);   
dfs(0,rooms,vis);//start from first room
for(int i = 0 ; i < n ; i++){
    if(!vis[i]) return false;
}
return true;
    }
};