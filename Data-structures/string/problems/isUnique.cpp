#include<bits/stdc++.h>
using namespace std;

// Implement an algorithm to determine if a string 
// has all unique characters.
// What if you cannot use additional data structures?

bool isUniquechar(string s) {
    // We can also immediately return false if the string length 
    // exceeds the number of unique characters in the alphabet. 
    // After all, you can't form a string of 280 unique characters out 
    // of a 128-character alphabet.
    if(s.length() > 128)
        return 0;

    bool char_set[128];
    for(int i=0; i<s.length(); i++) {
        int val = s[i];
        if(char_set[val])
            return 0;
        char_set[val] = 1;
    }
    return 1;
    // The time complexity for this code is O(n).
    // The space complexity isO(1).
}

bool isUniquechar_1(string s) {
    // We can reduce our space usage by a factor of eight by using a 
    // bit vector. We will assume, in the below code, that the string 
    // only uses the lowercase letters a through z. This will allow us 
    // to use just a single int.
    int checker = 0;
    for(int i=0; i<s.length(); i++) {
        int val = s[i] - 'a';
        if((checker & (1<<val)) > 0)
            return 0;
        checker = checker | (1<<val);
    }
    return 1;
    // The time complexity for this code is O(n).
    // The space complexity isO(1).
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    string s;
    cin>>s;
    cout<<isUniquechar_1(s);

    return 0;
}
