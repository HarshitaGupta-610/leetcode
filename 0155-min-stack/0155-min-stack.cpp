

// //Brute Force: push():O(1) ,pop():O(1) ,top():O(1) .getMin():O(n)
// class MinStack {
// public:
// stack<int>st;
//     MinStack() {     
//     }   
//     void push(int value) {
//      st.push(value);   
//     }  
//     void pop() {
//        st.pop(); 
//     }  
//     int top() {
//         return st.top();
//     }   
//     int getMin() {
//         stack<int>temp;
//    int mini = INT_MAX;
//      while(!st.empty()){
//         mini = min(mini,st.top());
//         temp.push(st.top());
//         st.pop();
//      }
//      while(!temp.empty()){
//         st.push(temp.top());
//         temp.pop();
//      }
//      return mini;
//     }
// };


//Optimal Approach : all in O(1)
/*
Main Stack (st) → Stores all elements.
Minimum Stack (minSt) → Stores the minimum element till that point.*/
class MinStack{
    public: 
    stack<int>minist;
    stack<int>st;
    MinStack(){    
    }
    void push(int val){
        st.push(val);
        if(minist.empty()) minist.push(val);
        else minist.push(min(val,minist.top()));
    }
    void pop(){
        st.pop();
        minist.pop();
    }
int top(){
    return st.top();
}
int getMin(){
    return minist.top();
}
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */