class Solution {
public:
    string reverseWords(string s) {
        //TC : O(n)
        //since last cheez first aayi hai:LIFO prinicple
        stringstream ss(s);
        string word;
        stack<string>st;
        while(ss>>word){
            st.push(word);
        }
        string ans ;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()) ans +=" ";
        }

return ans;
    }
};