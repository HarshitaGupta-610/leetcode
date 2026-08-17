class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string ans = "";

        // 1 se n+1 tak numbers ko process karenge
        for (int i = 0; i <= pattern.size(); i++) {

            // Current number stack mein daal do
            st.push(i + 1);

            // Agar 'I' mila ya pattern khatam ho gaya,
            // toh stack ko empty kar do
            if (i == pattern.size() || pattern[i] == 'I') {

                // Stack LIFO hai, isliye numbers reverse order mein niklenge
                // Ye 'D' sequence ko satisfy karega
                while (!st.empty()) {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }

        return ans;
    }
};