class Solution {
public:
    bool judgeCircle(string moves) {
        string s = moves;
        int n = s.size();
        int l = 0 ,  r = 0 , u = 0 , d = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'L'){
                 l++;
            }
            if(s[i] == 'R'){
                 r++;
            }
            if(s[i] == 'U'){
                 u++;
            }
            if(s[i] == 'D'){
                 d++;
            }
        }
        if( l == r && u == d){
            return true;
        }
        return false;
    }
};