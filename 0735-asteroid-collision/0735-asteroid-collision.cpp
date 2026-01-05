class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        for(int i = 0 ; i < a.size() ; i++){
            bool exploded = 0;
            while(!s.empty() &&  s.top() > 0 && a[i] < 0){
              if (abs(s.top()) < abs(a[i])) {
                    s.pop();
                    continue;  
                }
                else if (abs(s.top()) == abs(a[i])) {
                    s.pop();
                   exploded = 1;
                    break;
                }
                else {
                   exploded = 1;
                    break;
                }
            }
            if(exploded == 0){
          s.push(a[i]);
            }
        } 
        int n = s.size();
        vector<int> ans(n);
        for (int i = n -1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};