#include<bits/stdc++.h>
using namespace std;

int maxElement(int arr[], int size){
    int max = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i]>=max)
            max = arr[i];
    }
    return max;
}
void countSort(int arr[], int n){

    int max = maxElement(arr,n);
    vector<int> count(max+1,0);
    for(int i=0; i<n; i++)
        count[arr[i]]++;
    for(int i=1; i<count.size(); i++)
        count[i] += count[i-1];
    int output[n];
    for(int i=n; i>=0; i--){
        output[--count[arr[i]]] = arr[i];
    }
    for(int i=0; i<n; i++)
        arr[i] = output[i];
    
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    countSort(a,n);
    for(int i:a)
        cout<<i<<" ";
    return 0;
}
