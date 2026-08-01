class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        //Brute Force: O(NXN): erase krte rho jab tak string exists
        while(true){//loop run krta rahega jab tak hum ek flase condition pe na aajayein
        int l = s.size();
        int pos = s.find("()");
        if(pos != -1){
s.erase(pos,2);
        } 
         pos = s.find("{}");
        if(pos != -1) {s.erase(pos,2);
    }
         pos = s.find("[]");
        if(pos != -1) {s.erase(pos,2);
        }
if(l==s.size()) break;//pairs mile hi nahi
        }
       return s.empty();//empty hoti toh sab valid detected and erased

    }
};