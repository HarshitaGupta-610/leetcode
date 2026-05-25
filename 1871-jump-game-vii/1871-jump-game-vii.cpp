class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        int farthest = 1;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthest);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {

                if (s[j] == '0' && !visited[j]) {

                    if (j == n - 1){
                        return true;
                    }

                    visited[j] = true;
                    q.push(j);
                }
            }

            farthest = end + 1;
        }

        return n == 1;
    }
};