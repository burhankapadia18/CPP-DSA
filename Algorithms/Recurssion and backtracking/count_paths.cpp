#include<bits/stdc++.h>
using namespace std;

int count_paths(int s, int e) {

    if(s == e)
        return 1;
    if(s > e)
        return 0;

    int count = 0;
    for(int i = 1; i <= 6; i++)
        count += count_paths(s+i,e);

    return count;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    cout<<count_paths(1,5);

    return 0;
}