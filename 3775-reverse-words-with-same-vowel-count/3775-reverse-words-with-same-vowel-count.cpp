class Solution {
public:
    int vow(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;
        ss >> word;
        int firstVowels = vow(word);
        result = word;
        while (ss >> word) {
            if (vow(word) == firstVowels) {
                reverse(word.begin(), word.end());
            }
            result += " " + word;
        }

        return result;
    }
};

