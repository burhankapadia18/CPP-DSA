#include<bits/stdc++.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    stack<char> S;

    string s;
    cin>>s;
    
    int i=0;
    while(s[i]!='x' && i<s.length()){
        S.push(s[i]);
        i++;
    }
    i++;
    // cout<<s.substr(i)<<endl;
    // char c;
    // while(!S.empty()){
    //     c = S.top();
    //     cout<<c;
    //     S.pop();
    // }
    while(!S.empty() && s[i]){
        if(S.top() == s[i]){
            S.pop();
            i++;
        }
    }
    if(!s[i] && S.empty())
        cout<<"pallindrome";
    else 
        cout<<"not a pallindrome";

    return 0;
}