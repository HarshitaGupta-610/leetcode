class Solution {
public:
    bool doesAliceWin(string s) {
     //ek time pe ek hi vowl hatate jao alice ki side se
     //jab tak vowel hai tab tak alice else nahi
     for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            return true;
        }
     } 
     return false;  
    }
};