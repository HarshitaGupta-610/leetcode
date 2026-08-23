class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

//Brute force : O(n²)
//  for (int i = 0; i < numbers.size(); i++) {
//             for (int j = i + 1; j < numbers.size(); j++) {
//                 if (numbers[i] + numbers[j] == target) {
//                     return {i + 1, j + 1};
//                 }
//             }
//         }
//         return {};

   
   //Optimal : O(N)
        int l = 0;
        int r = numbers.size() - 1;
        while( l < r){
            if(numbers[l] + numbers[r] == target){
                return  { l + 1 , r + 1};
            }
            else if(numbers[l] + numbers[r] > target){
                r--;
            }
            else{
                l++;
            }
        }
        return{-1,-1};
    }
};