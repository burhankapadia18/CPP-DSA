#include<bits/stdc++.h>
using namespace std;

int main() {

   #ifndef ONLINE_JUDGE
      freopen("/Users/burhankapdawala/input.txt","r",stdin);
      freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

   int r, c;
   cin>>r>>c;

   int arr[r][c];
   for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
         cin>>arr[i][j];

   // int r1, c1;
   // cin>>r1>>c1;

   // int a[r1][c1];
   // for(int i=0; i<r1; i++)
   //    for(int j=0; j<c1; j++)
   //       cin>>a[i][j];

   // matrix transpose
   // **********************************
   // for(int i=0; i<r; i++)
   //    for(int j=i; j<c; j++){
   //       int temp = arr[i][j];
   //       arr[i][j] = arr[j][i];
   //       arr[j][i] = temp;
   //    }

   // matrix multiplication
   // **********************************
   // int ans[r][c1];
   // for(int i=0; i<r; i++)
   //    for(int j=0; j<c1; j++)
   //       ans[i][j] = 0;

   // for(int i=0; i<r; i++){
   //    for(int j=0; j<c1; j++){
   //       for(int k=0; k<c; k++){
   //          ans[i][j] += arr[i][k] * a[k][j];
   //       }
   //    }
   // }

   // 2Dmatrix search (sorted matrix)
   // **********************************
   // int i=0, j = c-1, target;
   // cin>>target;
   // bool found = false;
   // while(i < r && j >= 0){
   //    if(arr[i][j] == target){
   //       found = true;
   //       break;
   //    }
   //    if(arr[i][j] > target)
   //       j--;
   //    else 
   //       i++;
   // }
   // if(found)
   //    cout<<"available";
   // else 
   //    cout<<"not available";


   // for(int i=0; i<r; i++){
   //    for(int j=0; j<c1; j++)
   //       cout<<ans[i][j]<<'\t';
   //    cout<<endl;
   // }

   return 0;
}