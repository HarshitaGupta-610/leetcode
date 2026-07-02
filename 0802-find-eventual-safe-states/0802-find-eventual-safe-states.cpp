class Solution {
public:

    // DFS function
    // Returns true  -> Cycle found
    // Returns false -> No cycle found
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& visited,
             vector<int>& pathVisited,
             vector<int>& safe)
    {
        // Current node ko permanently visited mark kar do
        visited[node] = 1;

        // Current node ab current DFS path ka part hai
        pathVisited[node] = 1;

        // Current node ke saare neighbours ko visit karo
        for(int neighbour : graph[node])
        {
            // CASE 1:
            // Agar neighbour abhi tak visit nahi hua
            if(!visited[neighbour])
            {
                // DFS recursively neighbour ke graph ko explore karega
                // Agar niche kahin bhi cycle mili,
                // to true return hoga
                if(dfs(neighbour, graph, visited, pathVisited, safe))
                {
                    // Mere neighbour ko cycle mili
                    // Matlab mere through bhi cycle reachable hai
                    return true;
                }
            }

            // CASE 2:
            // Neighbour pehle se current recursion path me hai
            else if(pathVisited[neighbour])
            {
                // Back edge mil gayi
                // Directed graph me back edge = Cycle
                return true;
            }

            // CASE 3:
            // Neighbour pehle visit ho chuka hai
            // Aur current path me nahi hai
            // Is intuition code me hum kuch nahi kar rahe
        }

        // Agar yahan tak aa gaye
        // Matlab current node se koi cycle nahi mili

        // Current node safe hai
        safe[node] = 1;

        // DFS khatam ho gaya
        // Isliye current node ko recursion path se hata do
        pathVisited[node] = 0;

        // No cycle found
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();

        // visited[i]
        // 0 = Not visited
        // 1 = Visited
        vector<int> visited(n, 0);

        // pathVisited[i]
        // 0 = Current DFS path me nahi hai
        // 1 = Current DFS path me hai
        vector<int> pathVisited(n, 0);

        // safe[i]
        // 0 = Safe nahi pata
        // 1 = Safe node
        vector<int> safe(n, 0);

        // Graph disconnected ho sakta hai
        // Isliye har node se DFS start karenge
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i, graph, visited, pathVisited, safe);
            }
        }

        // Final answer store karega
        vector<int> ans;

        // Jo nodes safe hain unhe answer me daal do
        for(int i = 0; i < n; i++)
        {
            if(safe[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};