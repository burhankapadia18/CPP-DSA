#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int data){

    if(s.empty()){
        s.push(data);
        return;
    }

    int temp;
    temp = s.top(); s.pop();
    insert_at_bottom(s,data);
    s.push(temp);
}
void reverse(stack<int> &s){

    if(s.empty())
        return;

    int a = s.top(); s.pop();
    reverse(s);
    insert_at_bottom(s,a);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    stack<int> s;
    int n, data;
    cin>>n;
    while(n--){
        cin>>data;
        s.push(data);
    }
    // while(!s.empty()){
    //     data = s.top(); s.pop();
    //     cout<<data<<' ';
    // }
    // cout<<endl;

    reverse(s);
    while(!s.empty()){
        data = s.top(); s.pop();
        cout<<data<<' ';
    }

    //cout<<s.empty();

    return 0;
}