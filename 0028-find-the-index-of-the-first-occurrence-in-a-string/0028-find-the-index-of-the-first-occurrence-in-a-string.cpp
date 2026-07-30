class Solution {
public:
    int strStr(string haystack, string needle) {


        //Brute Force : O(m*n)
        /*
        Try matching the needle from every possible starting index of the 
        haystack; if all characters match, return that index,
         otherwise continue searching*/
        // int m = haystack.size();
        // int n = needle.size();
        // for(int i= 0 ; i < m-n ; i++){
        //     int j = 0;
        //     while(j < n && haystack[i+j] == needle[j]){
        //         j++;             
            
        //     if(j==n) return i;
        //     }
        // }
        // return -1;
//Better : TC O(m) use of find function :string.find(substring);
return haystack.find(needle);

      }
};