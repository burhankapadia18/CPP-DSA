#include<bits/stdc++.h>
using namespace std;

int countPathMaze(int n, int i, int j) {

    if(i == n-1 && j == n-1)
        return 1;
    if(i >= n || j >= n)
        return 0;

    return countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1);
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    cout<<countPathMaze(6,0,0);

    return 0;
}