class Solution {
public:
    string countAndSay(int n) {
if(n==1) return "1";// base case

//Brute force:
        string curr = "1";//intially we have
for(int step = 2 ; step <= n ;step++){
string next ="";//append hone wali new string
for(int i = 0 ; i < curr.size();){
    int count = 1;
for(int j = i +1 ; j < curr.size();j++){
if(curr[i] == curr[j]) count++;
else break;
}
next += to_string(count);
next+=curr[i];
i+=count ;
}
curr = next;
}
return curr;
        
    }
};