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
vector<int>v;
void addNum(int num){
    auto it = lower_bound(v.begin() , v.end() , num); // us number ki sahi posiiton pe insertion ho jaaye
    v.insert(it,num);
}
double findMedian(){
    int n = v.size();
    if( n % 2 != 0){
        return v[n/2];
    }else{
        return (v[n/2] + v[n/2 - 1]) / 2.0;  
    }
}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */