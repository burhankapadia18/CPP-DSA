/*
Algorithm:
    1 Scan the Postfix string from left to right.
    2 Initialize an empty stack.
    3 Repeat steps 4 and 5 till all the characters are scanned.
    4 If the scanned character is an operand, push it onto the 
      stack.
    5 If the scanned character is an operator, and if the operator 
      is a unary operator, then pop an element from the stack. If 
      the operator is a binary operator, then pop two elements 
      from the stack. After popping the elements, apply the 
      operator to those popped elements. Let the result of this 
      operation be retVal onto the stack.
    6 After all characters are scanned, we will have only one 
      element in the stack.
    7 Return top of the stack as result.
*/

// incomplete

#include<iostream>
#include<stack>
#include<string>

using namespace std;

float perform_operation(int a, int b, char c){
    if(c == '+') 
        return a + b;
	else if(c == '-') 
        return a - b;
	else if(c == '*') 
        return a * b;
	else if(c == '/') 
        return a / b;

	else cout<<"Unexpected Error \n";
	return -1;
}

int isnum(char c){
    if(c>='0' && c<='9')
        return 1;
    return 0;
}

float evaluate_postfix(string exp){
    stack<float> s;
    for(int i=0; i<exp.length(); i++){
        if(isnum(exp[i])){
            s.push(float(exp[i]));
        }
        else {
            float a1 = s.top(); s.pop();
            float a2 = s.top(); s.pop();
            float result = perform_operation(a1, a2, exp[i]);
            if(result == -1){
                cout<<"wrong expression";
                return 0;
            }
            else {
                s.push(result);
            }
        }
    }
    return s.top();
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    string expression;
    cin>>expression;
    cout<<evaluate_postfix(expression);
    
    return 0;
}