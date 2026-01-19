class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        bool Vow = false;
        bool Con = false;

        if(n < 3){
             return false;
        }
        
        for(int i=0; i<n; i++){
            if(!(isalnum(word[i]))) {
                return false;
            }
            if(isalpha(word[i])){
                int lower = tolower(word[i]);
                if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
                     Vow = true;
                }
                else {
                    Con = true;
                }
            }
        }
        if(Vow && Con){
            return true;
        }
        return false;
    }
};