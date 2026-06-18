class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>a;

        int maxi = 0 , smaxi = 0;
        for(int num : nums){
            a[num]++;
        }
        vector<pair<int,int>>v;
        for(auto it : a){
            v.push_back({it.second , it.first});
        }
        sort(v.rbegin() , v.rend());
        vector<int>ans;
        for(int i = 0 ; i < k ; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};