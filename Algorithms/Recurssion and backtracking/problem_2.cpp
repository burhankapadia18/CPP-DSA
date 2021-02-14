#include<bits/stdc++.h>
using namespace std;

int checkSorted(int arr[], int n){
    
    if(n == 1)
        return 1;

    if(arr[n-1] >= arr[n-2])
        return checkSorted(arr,n-1);
    else 
        return 0;
}

int main(){

    int arr[] = {3,2,3,4,5,6};
    cout<<checkSorted(arr,6);

    return 0;
}