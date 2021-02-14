#include<iostream>
using namespace std;

void spiral_traversal(int a[][100], int n, int m){
    int row_start = 0;
    int row_end = n-1;
    int column_start = 0;
    int column_end = m-1;

    while(row_start <= row_end && column_start <= column_end){

        // for row start
        for(int col = column_start; col<=column_end; col++)
            cout<<a[row_start][col]<<" ";
        row_start++;

        // for column end 
        for(int row = row_start; row<=row_end; row++)
            cout<<a[row][column_end]<<" ";
        column_end--;

        // for row end
        for(int col = column_end; col>=column_start; col--)
            cout<<a[row_end][col]<<" ";
        row_end--;

        // for column start
        for(int row = row_end; row>=row_start; row--)
            cout<<a[row][column_start]<<" ";
        column_start++;
    }
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;

    int a[100][100];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<'\t';
        }
        cout<<'\n';
    }
    cout<<endl<<endl;
    spiral_traversal(a,n,m);

    return 0;
}