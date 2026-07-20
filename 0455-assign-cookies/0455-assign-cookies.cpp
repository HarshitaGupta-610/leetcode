class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
int greed = g.size();
int sizes = s.size();
        // //brute froce : O(N X M + nlogn + mlogm)
        // //cookies aur greed ko sort karke min needs dheere
        // //fulfill karte jao
        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());
        // vector<int>used(sizes,0);
        // int count = 0;
        // for(int i = 0 ; i < greed ; i++){
        //     for(int j = 0 ; j < sizes ; j++){
        //         if(s[j] >= g[i] && used[j] ==0 ){
        //             used[j] = 1;
        //             count++;
        //             break; // is bache ko milgaya agli greed dekho
        //         }
        //     }
        // }
        // return count;


        //Brute force : O(nlong + mlogm)
        //ek bar j use hogya toh next j se start karo
        // sort(g.begin() , g.end());
        // sort(s.begin() , s.end());
        // int start = 0 ;//cookies index to start with 
        // int ans = 0;
        // for(int i = 0 ; i < greed ; i++){
        //     for(int j = start ; j < sizes ; j++){
        //         if(s[j] >= g[i]){
        //             ans++;
        //             start = j +1;
        //             break;
        //         }
        //     }
        // }
        // return ans;



        //optimal : O(nlogn + mlogm)
        /*sort karke simulataneously tarverse karte raho aur cookies assign karte raho
        */
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int i = 0 , j = 0;// i is for student , j for cookies

        while( i < greed && j < sizes){
if(s[j] >= g[i]){
    i++ , j++;

}
else{
    j++;//ye cookie toh kisi kaam ka nahi aage wale ka dekhege
}
        }
        return i;
    }
};