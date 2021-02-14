#include<iostream>
using namespace std;

void pairsum(int arr[], int n, int k){
    sort(arr, arr + n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    int low = 0, high = n-1;
    while(low < high){
        if(arr[low]+arr[high] == k){
            cout<<low<<" "<<high;
            return;
        }
        else if(arr[low]+arr[high] > k)
            high--;
        else 
            low++;
    }
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    int k;
    cin>>k;
    
    pairsum(a,n,k);

    return 0;
}