class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()){
         return false;
        }
        vector<int>s1(256,-1);
        vector<int>t1(256,-1);

        for(int i = 0 ; i < s.size() ; i++){
            if(s1[s[i]] != t1[t[i]]){
                return false;
            }
            s1[s[i]] = t1[t[i]] =i;
        }
        return true;

      
       
    }
};
