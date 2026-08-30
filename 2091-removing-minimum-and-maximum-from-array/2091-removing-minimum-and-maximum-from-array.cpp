class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
int n = nums.size();
//O(n):Ek traversal

int miniI = 0 , maxiI = 0;//initialising indices which are positions of minimum and maximum
for(int i = 1 ; i < n ; i++){
    if(nums[i] < nums[miniI]){
        miniI = i;
    }
    if(nums[i] > nums[maxiI]){
        maxiI = i;
    }
}
int left = min(miniI , maxiI);//smaller position kitni pass hai ..aage se count krege
int right = max(miniI , maxiI);//badi position kitni dur hai...peeche tak kahan jaana hai
int option1 = right + 1; //Kyuki right dono elements mein bada index hai. Front se dono remove karne hain toh us bade index tak jaana padega.
int option2 = n - left;// Back se aate hue hume chhote index tak jaana padega.
 int option3 = left + 1 + n - right;  // one from each side : right and left
 return min({option1 , option2 , option3});
    }
};