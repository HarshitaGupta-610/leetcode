class Solution {
public:
    int evalRPN(vector<string>& tokens) {
  /*
  Use a stack to store operands and evaluate whenever an operator appears*/      
  /*
  Number → push into stack
Operator → pop 2 numbers, perform operation, push result back*/
stack<int>st;
for(string token : tokens){
    if(token == "+" || token == "-" || token == "*" || token == "/"){ 
        //agar operators haain
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
if(token =="+") st.push(num1+num2);
else if(token =="-")st.push(num1 - num2);
else if(token =="*")st.push(num1 * num2);
else st.push(num1 / num2);
    }
    else{
        st.push(stoi(token));//number hai
    }
}
return st.top();
    }
};