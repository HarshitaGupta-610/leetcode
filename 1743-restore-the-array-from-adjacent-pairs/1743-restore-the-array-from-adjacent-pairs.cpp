class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& macentPairs) {
   //in O(N)

   //  // Map each number to all the numbers directly connected to it.    
   unordered_map<int,vector<int>>m;
   /*
   // Build the macency list.
        // Every pair [a,b] means a and b are macent,
        // so we store the connection in BOTH directions.*/
 for (auto &it : macentPairs) {
            int a = it[0];
            int b = it[1];
            m[a].push_back(b);
            m[b].push_back(a);
        }//pehla element dhundho
        int start;
 for (auto &it : m) {
            if(it.second.size() ==1){
                start = it.first;
                break;
            }
        }
        vector<int>ans;
        int curr = start;
         int prev = INT_MAX;
    
 while (true) {
// Add the current number to the answer.
ans.push_back(curr);
bool found = false;
// Check all neighbours of the current number.
for (int next : m[curr]) {
if (next != prev) {
// Move forward.
prev = curr;
curr = next;
 found = true;
 break;
}
}
if (!found) break;
 }
        return ans;
    }
};