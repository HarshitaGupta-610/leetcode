class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;      // Valid directory names store karega
        string curr = "";      // Current directory name banane ke liye

        // Path ke end tak traverse karenge
        // i == path.size() isliye liya taaki last folder bhi process ho jaye
        for (int i = 0; i <= path.size(); i++) {

            // Agar slash mila ya string khatam ho gayi,
            // iska matlab ek directory name complete ho gaya
            if (i == path.size() || path[i] == '/') {

                // Case 1:
                // "" -> Multiple slashes (//)
                // "." -> Current directory, ignore kar do
                if (curr == "" || curr == ".") {
                    // Kuch nahi karna
                }

                // Case 2:
                // ".." -> Parent directory jana hai
                else if (curr == "..") {

                    // Agar stack empty nahi hai,
                    // toh ek directory upar chale jao
                    if (!st.empty()) {
                        st.pop();
                    }

                    // Agar stack empty hai,
                    // matlab already root pe ho,
                    // aur upar nahi ja sakte
                }

                // Case 3:
                // Normal directory name hai
                else {
                    st.push(curr);
                }

                // Agla directory name banana start karo
                curr = "";
            }

            // Slash nahi mila,
            // current folder name banate jao
            else {
                curr += path[i];
            }
        }

        // Stack reverse order me hai,
        // isliye pehle vector me daalenge
        vector<string> temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        // Correct order lane ke liye reverse
        reverse(temp.begin(), temp.end());

        string ans = "";

        // Har directory ke aage '/'
        for (string dir : temp) {
            ans += "/" + dir;
        }

        // Agar koi directory nahi bachi
        // toh answer sirf root "/"
        if (ans.empty())
            return "/";

        return ans;
    }
};