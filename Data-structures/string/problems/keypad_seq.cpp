#include<bits/stdc++.h>
using namespace std;

string keypadArr[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void keypad(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string code = keypadArr[ch-'0'];
    string ros = s.substr(1);
    for(int i=0; i<code.length(); i++)
        keypad(ros,ans+code[i]);
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    keypad("287426","");

    return 0;
}