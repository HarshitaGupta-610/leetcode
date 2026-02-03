class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4){
            return false;
        }

        int i = 1;

        int start = i; 
        while(i < n && nums[i] > nums[i-1]){
            i++;
        }
        if(i == start || i == n){ 
            return false;
        }

        start = i;  
        while(i < n && nums[i] < nums[i-1]){
            i++;
        }
        if(i == start || i == n){  
            return false;
        }

        start = i;  
        while(i < n && nums[i] > nums[i-1]){
            i++;
        }

        if(i == n && i != start){
            return true;
        } 
        return false;
    }
};
