class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
int n = temperatures.size();
 //Brute force: Har din ke liye aage warmer day search karo :O(n²)  
//  vector<int>ans(n,0);  
// for(int i = 0 ; i < n ; i++){
//     for(int j = i +1; j < n ; j++){
// if(temperatures[j] > temperatures[i]){
//     ans[i] =(j-i);
//     break;
// }
//     }
// }
// return ans;


//Optimal : O(N) Use of stacks
stack<int>st;
vector<int>ans(n);
for(int i = n-1;i>=0;i--){
    while(!st.empty() && temperatures[i]>= temperatures[st.top()] ){
        st.pop();
    }
    if(st.empty()) ans[i] = 0;
    else ans[i] = st.top()-i;
    st.push(i);
}
return ans;
    }
};