class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 0));

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            int r=curr.first;
            int c=curr.second;

            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<m &&nc>=0 && nc<n && !vis[nr][nc])
                {
                    vis[nr][nc]=1;

                    dist[nr][nc]=dist[r][c]+1;

                    q.push({nr,nc});
                }
            }
        }

        return dist;
    }
};