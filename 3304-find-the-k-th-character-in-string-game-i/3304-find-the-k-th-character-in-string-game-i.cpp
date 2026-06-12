class Solution {
public:

string append(string s , int k){
   if(s.size() >= k){
    return s;
   }
 string temp = "";
 for(int i = 0 ; i < s.size() ; i++){
    temp+= char(s[i] +1);
 }
 s+= temp;
 return append(s,k);
}

    char kthCharacter(int k) {
       string s = "";
       s+='a';
      string ans = append(s,k);
      return ans[k-1];
    }
};