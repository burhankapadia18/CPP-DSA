#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){
    
    if(s.length()==0)
        return "";
    
    char c = s[0];
    string ans = removeDuplicates(s.substr(1));
    if(c == ans[0])
        return ans;
    else 
        return c+ans;
}

string move_x_to_last(string s){
    
    if(s.length()==0)
        return "";

    char c = s[0];
    string ans = move_x_to_last(s.substr(1));
    if(c == 'x')
        return ans+c;
    else 
        return c+ans;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    string s = "";

    return 0;
}