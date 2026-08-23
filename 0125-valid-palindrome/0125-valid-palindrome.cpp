class Solution {
public:
    bool isPalindrome(string s) {
   //Brute force: time and space O(N)
//    string final = "";
//    for(char c : s){
//     if(isalnum(c)){
//         final += tolower(c);
//     }
//    }
//    int l = 0 , r = final.size() - 1;
//    while( l < r){
//     if(final[l] != final[r]){
//         return false;
//     }
//     l++;
//     r--;
//    } 
//    return true;    


//Optimal : O(N) tc and sc O(1)
int l = 0 , r = s.size() - 1;
while( l < r)
{
    while( l < r && !isalnum(s[l])){
        l++;
    }
    while( l < r && !isalnum(s[r])){
        r--;
    }

    if(tolower(s[l]) != tolower(s[r])){
        return false;
    }
    l++;
    r--;
}
return true;
    }
};