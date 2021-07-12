#include<iostream>
#include<stack>

using namespace std;

class advancedStack {
public:
    stack<int> element_stack;
    stack<int> min_stack;

    void push(int data){
        element_stack.push(data);
        if(min_stack.empty() || min_stack.top()>=data)
            min_stack.push(data);
        else 
            min_stack.push(min_stack.top());
    }
    void pop(){
        if(element_stack.empty())
            cout<<"advanced stack is empty";
        else {
            element_stack.pop();
            min_stack.pop();
            }
    }
    void getmin(){
        cout<<min_stack.top();
    }
};

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif
    
    advancedStack s;
    s.push(2);
    s.getmin();

    return 0;
}