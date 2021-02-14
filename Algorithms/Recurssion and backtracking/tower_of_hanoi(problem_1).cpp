#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char src, char des, char hlpr){

    if(n==0)
        return;

    towerOfHanoi(n-1,src,hlpr,des);
    cout<<"put from "<<src<<" to "<<des<<endl;
    towerOfHanoi(n-1,hlpr,des,src);
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    towerOfHanoi(3,'A','B','C');

    return 0;
}