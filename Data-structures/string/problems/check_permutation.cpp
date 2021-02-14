#include<bits/stdc++.h>
using namespace std;

// Given two strings, write a method to decide if 
// one is a permutation of the other

bool permutation_1(string s, string t){

    if(s.length() != t.length())
        return 0;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(!s.compare(t))
        return 1;
    else 
        return 0;
}

bool permutation_2(string s, string t) {

    if(s.length() != t.length())
        return 0;

    int char_set[128] = {0};
    int val;
    for(int i=0; i<s.length(); i++) {
        val = s[i];
        char_set[val]++;
        val = t[i];
        char_set[val]--;
    }
    for(int i=0; i<128; i++)
        if(char_set[i])
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    string s, t;
    cin>>s>>t;

    cout<<permutation_2(s,t);

    return 0;
}
