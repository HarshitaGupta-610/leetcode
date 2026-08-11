class Solution {
public:


//Brute Force: generate every possible arrangement of the string and check whether it is valid
//O( n  X n!)
// bool isValid(string &s){
//     for(int i = 1 ; i < s.size() ; i++){
//         if(s[i] == s[i-1]){
//             return false;
//         }
//     }
//     return true;
// }
// string reorganizeString(string s) {
//         int n = s.size();
// sort(s.begin() , s.end());
// do{
//     if(isValid(s)){
//         return s;
//     }
// }while(next_permutation(s.begin() , s.end()));
// return "";
//     }



//Brute force:Generate every possible permutation and check each permutation for adjacent duplicate characters. O(n × n!)
//answer building
//     bool solve(string remaining, string &ans) {
//         // If no characters are left, all used
//         if(remaining.empty()) {
//             return true;
//         }
//         // Try every character from remaining string
//         for(int i = 0; i < remaining.size(); i++) {
//             char ch = remaining[i];
// //skip for same character
//             if(!ans.empty() && ans.back() == ch) {
//                 continue;
//             }
//             ans.push_back(ch);
//             string next = remaining.substr(0, i)
//                         + remaining.substr(i + 1);
//             if(solve(next, ans)) {
//                 return true;
//             }
//             ans.pop_back();
//         }
//         return false;
//     }


//     string reorganizeString(string s) {
//         string ans = "";
//         if(solve(s, ans)) {
//             return ans;
//         }
//         return "";}


//Optimal:Use a max heap to always pick the most frequent character, while temporarily keeping the previously used character out of the heap.O(n log 26) = O(n)
    string reorganizeString(string s) {
        // Count frequency of every character
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        // Max heap:{frequency, character}
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
            }
        }
        string ans = "";
        int prevFreq = 0;
        char prevChar = '#';
        while(!pq.empty()) {
            auto [currentFreq, currentChar] = pq.top();
            pq.pop();
            ans += currentChar;
            currentFreq--;
            if(prevFreq > 0) {
                pq.push({prevFreq, prevChar});
            }
            prevFreq = currentFreq;
            prevChar = currentChar;
        }
        if(ans.size() != s.size()) {
            return "";
        }

        return ans;
    }
};
