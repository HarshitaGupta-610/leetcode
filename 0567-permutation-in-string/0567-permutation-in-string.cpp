class Solution {
public:
    bool checkInclusion(string s1, string s2) {
int n1 = s1.size();
int n2 = s2.size();

    //Brute : o(n2 * log n1)    
    // sort(s1.begin() , s1.end());
    // for(int i = 0 ; i <= n2 - n1; i++){
    //     string temp = s2.substr(i,n1);
    //     sort(temp.begin() , temp.end());
    //     if(temp == s1) return true;
    // }
    // return false; 


     //Optimal : O(n1 +n2)
     if(n1 > n2) return false;
     vector<int>freq1(26,0);       
     vector<int>freq2(26,0);

     for(char c : s1){
        freq1[c-'a']++;
     }
     for(int i = 0 ; i < n1 ; i++){
        freq2[s2[i] - 'a']++;
     }  
     if(freq1 == freq2) return true;
     for(int i = n1 ; i < n2 ; i++){
        freq2[s2[i] - 'a']++;
        freq2[s2[i - n1] - 'a']--;//pichla character
         if(freq1 == freq2) return true;
     }     
     return false;
    }
};