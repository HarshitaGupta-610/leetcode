class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();
        if(n == 0) return {};
//Brute force: ek set mein smaller insert krte gaye and rank would be setsize+1(n²logn)

//         vector<int>ans;
//         if(n == 1){
//             ans.push_back(1);
//             return ans ;
//         }           
//           for(int i = 0 ; i < n ; i++){
// set<int>a;
// for(int j = 0 ; j < n  ; j++){
//     if(j == i)continue;
//     if(arr[j] < arr[i]){
//            a.insert(arr[j]);  
//     }
// }
// ans.push_back(a.size() + 1);
//           }          
//         return ans;



vector<int>temp = arr;
sort(temp.begin() , temp.end());
map<int,int>s;
int rank = 1;
s[temp[0]] = 1;
for(int i = 1 ; i < n; i++){
    if(temp[i] != temp[i-1]){
        rank++;
        s[temp[i]] = rank;
    }
   
}
for(int i = 0 ; i < n ; i++){
    arr[i] = s[arr[i]];
}
return arr;

    }
};