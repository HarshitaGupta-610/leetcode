class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});


        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int distance = it.first;
            int node = it.second;

            for(auto padosi : adj[node]){
                int next = padosi.first;
                int weight = padosi.second;

                if(distance + weight < dist[next]){
                    dist[next] = distance + weight;
                    pq.push({dist[next] , next});
                }
            }
        }

            int ans = 0;
            for(int i = 1 ; i <= n ; i++){
                if(dist[i] == INT_MAX){
                    return -1;
                }
                ans = max(ans,dist[i]);
            }
        
        
        return ans;
    }
};