class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    //At most 2 elements can occur more than n/3 times because 3 elements × more than n/3 occurrences would require more than n total elements, which is impossible.

    //Boyer-Moore Voting Algorithm. Since at most two elements can occur more than n/3 times, I maintain two candidates and their vote counts. Different elements cancel one vote from both candidates. After finding the two potential candidates, I do a second pass to verify their actual frequencies.: O(n)
        int n = nums.size();
 int num1 = -1 , num2 = -1, count1 = 0 ,count2 = 0;
 for(int i = 0 ; i < n ; i++){
    if(nums[i] == num1) count1++;
    else if(nums[i] == num2) count2++;
    else if(count1 ==0) {
        num1 = nums[i] ;
        count1 = 1;
    } else if(count2 == 0){
        num2 = nums[i];
        count2 = 1;
    }
    else {
        count1--;
        count2--;
    }
 }  
 vector<int>ans;
 count1 = 0 ;
 count2 = 0;
 for(int i = 0 ; i < n; i++){
if (nums[i] == num1)count1++;
else if (nums[i] == num2)count2++;
 }
if(count1 > n/3) ans.push_back(num1);    
if(count2 > n/3) ans.push_back(num2);    
return ans;
    }
};