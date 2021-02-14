#include<bits/stdc++.h>
using namespace std;

void subseq(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }    

    char ch = s[0];
    string ros = s.substr(1);

    subseq(ros,ans);
    subseq(ros,ans+ch);
}

void subseq_with_ASCII(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subseq(ros,ans);
    subseq(ros,ans+ch);
    subseq(ros,ans+to_string(code));
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    subseq("ABC","");

    return 0;
}