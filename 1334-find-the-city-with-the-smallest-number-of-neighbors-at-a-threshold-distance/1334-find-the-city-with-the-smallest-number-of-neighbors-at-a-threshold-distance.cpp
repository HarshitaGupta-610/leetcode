class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distThreshold) {
        //For every city → find shortest dist to all other cities → count those ≤ threshold → choose minimum count.

        //1.create adjacency list of node connection and the edge wieght between them:adj[u] = {v, weight}
 vector<vector<pair<int,int>>>adj(n);
for(auto &edge : edges){
 int u = edge[0];
int v = edge[1];
int wt = edge[2];
adj[u].push_back({v,wt});
adj[v].push_back({u,wt});
}
 int ans = -1;//ans final wala
 int mini = INT_MAX;//min reachable cities
 for(int i = 0 ; i < n ; i++){
    vector<int>dist(n,INT_MAX);// dist[city] = shortest dist from source i to city
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 dist[i] = 0;
pq.push({0,i});
while(!pq.empty()){
auto[d,node] = pq.top();// Get node having smallest dist:min heap hai toh top pe minimum
pq.pop();
if(d > dist[node]) continue;
for(auto &[next,wt] : adj[node]){
 if(d + wt < dist[next]) {
dist[next] = d + wt;
pq.push({dist[next], next});
}
}
}
int count = 0;
 for(int city = 0; city < n; city++) {
if(city != i && dist[city] <= distThreshold) {
count++;
 }
 }
 if(count <= mini) {
mini= count;
ans = i;
}
}
return ans;
}
};