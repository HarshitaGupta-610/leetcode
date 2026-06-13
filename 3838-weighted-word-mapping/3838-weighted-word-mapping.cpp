class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       map<char,int> mp;
        int n2 = weights.size();
        for(int i = 0 ; i < n2 ; i++){
            mp['a' + i] = weights[i];
        }
        string ans = "";
        int n1 = words.size();
        for(string word : words){
            
            int sum = 0;

            for(char c : word){
                sum += mp[c];   // get weight from map
            }

            int mod = sum % 26;

            char mapped = 'z' - mod;  // reverse mapping
            ans += mapped;
        }

        return ans;
        
    }
};