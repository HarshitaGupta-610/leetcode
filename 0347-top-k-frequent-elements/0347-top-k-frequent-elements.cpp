class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
     

     //Brute force: O(N X N)
unordered_map<int,int>m;
for(int i = 0 ; i < n ;i++){
    int count = 0;
    for(int j = 0 ; j < n ; j++ ){
        if(nums[i] == nums[j]){
            count++;
        }
    }
    m[nums[i]] = count;
}


vector<pair<int,int>> freq;
for(auto it : m){
freq.push_back({it.second , it.first});
}
sort(freq.begin() , freq.end() , greater<pair<int,int>>());
vector<int>ans;
unordered_set<int>s;
for(auto it : freq){
    if(s.find(it.second) == s.end()){
        ans.push_back(it.second);
        s.insert(it.second);
    }
     if(ans.size() ==k){
        return ans;
    }
}
   
    return{};
    }

};