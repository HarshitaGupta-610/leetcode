class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int start = 0, end = n-1, mid;
       while(start<=end){
       mid = (start + end)/2;
       if ( arr[mid] == key){
      
          return mid;
          
      }
      else if( key< arr[mid] ){
          end  = mid -1;
      }
      else{
          start = mid +1 ;
      }
   }
   
   return -1;
}
};
