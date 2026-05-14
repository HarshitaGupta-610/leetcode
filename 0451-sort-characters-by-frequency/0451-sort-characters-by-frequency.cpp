class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpi;
        for( char c: s){
            mpi[c]++;
        }
        vector<pair<char,int>>freqVec(mpi.begin() , mpi.end());
        sort(freqVec.begin() , freqVec.end() , [](auto &a , auto &b){           
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second ;
        });

        string ans = "";
        for(auto &p : freqVec){
            ans += string(p.second,p.first);
        }

     return ans;
    }
};