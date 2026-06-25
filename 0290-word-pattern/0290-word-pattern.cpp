class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> m1;   
        unordered_map<char, string> m2;   

        vector<string> words;
        stringstream ss(s);
        string word;
 while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string w = words[i];

            if (m1.find(w) == m1.end() && m2.find(ch) == m2.end()) {
                m1[w] = ch;
                m2[ch] = w;
            }
            else {
                if (m1[w] != ch || m2[ch] != w) {
                    return false;
                }
            }
        }

        return true;
    }
};