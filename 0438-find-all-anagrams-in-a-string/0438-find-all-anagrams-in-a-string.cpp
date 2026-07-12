class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        // Agar pattern string badi hai to answer kabhi nahi milega
        if (p.size() > s.size())
            return ans;

        // Pattern aur current window ki frequency store karenge
        vector<int> patternFreq(26, 0);
        vector<int> windowFreq(26, 0);

        // Pattern ki frequency count karo
        for (char ch : p)
            patternFreq[ch - 'a']++;

        int windowSize = p.size();

        // String s par sliding window chalayenge
        for (int i = 0; i < s.size(); i++) {

            // Current character ko window me add karo
            windowFreq[s[i] - 'a']++;

            // Agar window size exceed ho gaya,
            // to sabse purana character hata do
            if (i >= windowSize)
                windowFreq[s[i - windowSize] - 'a']--;

            // Agar dono frequency arrays same hain,
            // to ye window pattern ka anagram hai
            if (windowFreq == patternFreq)
                ans.push_back(i - windowSize + 1);
        }

        return ans;
    }
};