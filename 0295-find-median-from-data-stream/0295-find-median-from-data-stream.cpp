class MedianFinder {
public:
    MedianFinder() {
        
    }

    // Brute : O(nlogn ) as har time apne element daalke sort krte rahege
    // vector<int>v;
    // void addNum(int num) {
    //     v.push_back(num);
    // }
    
    // double findMedian() {
    //     sort(v.begin() , v.end());
    //     int n = v.size();
    //     if( n % 2 == 0){
    //         return (v[n/2] + v[(n/2) - 1] ) /  2.0;
    //     }
    //     else{
    //         return v[n/2];
    //     }
    // }


//Better Approach : O(log n)iterator ki insertion + O(n) for elements insertion ~ O(n)
//element ko daalo hi sahi position pe
// vector<int>v;
// void addNum(int num){
//     auto it = lower_bound(v.begin() , v.end() , num); // us number ki sahi posiiton pe insertion ho jaaye
//     v.insert(it,num);
// }
// double findMedian(){
//     int n = v.size();
//     if( n % 2 != 0){
//         return v[n/2];
//     }else{
//         return (v[n/2] + v[n/2 - 1]) / 2.0;  
//     }
// }

//Optimal : 
/*median ke liye left side ka maximum element aur right side ka minimum element chahiye
maximum top pe ho toh max heap , min top pe ho toh min heap
left ke liye max heap banayege aur right ke liye min heap
*/
priority_queue<int>left;
priority_queue<int,vector<int>,greater<int>>right;
void addNum(int num){
    if(left.empty() || num <= left.top()){
        left.push(num);
    }
    else{
        right.push(num);
    }
    if(left.size() > right.size() + 1){
        right.push(left.top());
        left.pop();
    }
    else if(right.size() > left.size()){
left.push(right.top());
right.pop();
    }
}
double findMedian(){
    if(left.size() == right.size()){
        return (left.top() + right.top()) / 2.0;
    }
    else{
        return left.top();
    }
}


};




/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */