class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // Final answer store karega
        vector<vector<int>> ans;

        // Min Heap
        // pair.first -> sum
        // pair.second.first -> index in nums1 (i)
        // pair.second.second -> index in nums2 (j)

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        // Har row ka first element heap me daal do
        // Matlab (i,0)

        for(int i = 0; i < min((int)nums1.size(), k); i++)
        {
            pq.push({
                nums1[i] + nums2[0],   // sum
                {i,0}                  // indices
            });
        }

        // Jab tak heap empty nahi hota
        // aur hume k pairs chahiye

        while(!pq.empty() && k--)
        {
            // Sabse chhoti sum wala pair nikalo
            auto temp = pq.top();
            pq.pop();

            // Indices nikaalo
            int i = temp.second.first;
            int j = temp.second.second;

            // Original pair answer me daalo
            ans.push_back({nums1[i], nums2[j]});

            // Same row ka next element heap me daalo
            // (i same rahega, j aage badhega)

            if(j + 1 < nums2.size())
            {
                pq.push({
                    nums1[i] + nums2[j + 1],
                    {i, j + 1}
                });
            }
        }

        return ans;
    }
};