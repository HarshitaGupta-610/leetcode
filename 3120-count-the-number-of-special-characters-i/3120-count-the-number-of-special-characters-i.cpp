class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int>m1;
        unordered_map<char, int>m2;
        for(char c : word){
            if( c >= 'A' && c <= 'Z'){
                m1[c]++;
            }
            else if( c >= 'a' && c <= 'z'){
                m2[c]++;
            }
        }
                int count = 0;
        for(char c = 'a'; c <= 'z'; c++) {

            if(m2[c] > 0 && m1[c - 32] > 0) {
                count++;
            }
        }

        return count;

    
    }
};