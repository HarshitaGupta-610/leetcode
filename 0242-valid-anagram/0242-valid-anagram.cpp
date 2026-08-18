class Solution {
public:
    bool isAnagram(string s, string t) {



//   //O(nlogn): sort and check
//    if (s.size() != t.size())
//             return false;

//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         return s == t;     
//     }


//Tc:O(n)
if (s.size() != t.size())
            return false;

        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }

        return true;
    }
};