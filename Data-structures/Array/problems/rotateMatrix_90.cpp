#include<bits/stdc++.h>
using namespace std;

// Given an image represented by an NxN matrix, where each pixel in the 
// image is 4 bytes, write a method to rotate the image by 90 degrees.

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int N;
    cin>>N;
    int a[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>a[i][j];

    for(int i=0; i<N/2; i++) {
        for(int j=i; j<N-1-i; j++) {
            // swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N-1-j][i];
            a[N-1-j][i] = a[N-1-i][N-1-j];
            a[N-1-i][N-1-j] = a[j][N-1-i];
            a[j][N-1-i] = temp;
        }
    }


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<a[i][j]<<'\t';
        cout<<'\n';
    }

    return 0;
}
