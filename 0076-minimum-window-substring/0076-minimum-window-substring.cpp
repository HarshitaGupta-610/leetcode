class Solution {
public:
    string minWindow(string s, string t) {
        //t ka har character s ki window mein hona chahiye
  int m = s.size();
  int n = t.size();

//   TC → O(m + n)
// SC → O(1)
  if(n > m) return "";//agar t badi hai toh possble hi nahi      
vector<int>freq(128,0);//total ASCII characters maanke chalege hum
for(char c : t){
    freq[c]++;//t ke characters
}
int l = 0;//window start
int count = 0;//t ke kitne characters is window mein hume mil gaye hain
int start = 0;//Minimum window kahan se start hoti hai.
int minLen = INT_MAX;//Minimum window ki length.
for(int r = 0 ; r < m ; r++){
    if(freq[s[r]] > 0) count++;//Ye character t mein required hai aur abhi humein iski zarurat hai.
    freq[s[r]]--;//ye mil chuka hai
while(count == n){
    //window ko jitna chota kar payein keeping all required characters
    int len = r-l+1;
    if(len < minLen) {
    minLen = len;
    start = l;////ye window kahan se start hui
}
freq[s[l]]++;//Hum s[l] ko window se bahar nikal rahe hain, toh us character ki available/required frequency ko wapas increase karna padega.
if(freq[s[l]] > 0)count--;//Check karo required character nikla kya
l++;
}
}
return minLen == INT_MAX ? "" :s.substr(start,minLen);

    }
};