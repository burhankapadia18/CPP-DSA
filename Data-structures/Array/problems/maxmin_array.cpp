#include<iostream>

using namespace std;

void MaxMin(int arr[], int size){
    int max = arr[0], min = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>=max)
            max = arr[i];
        if(arr[i]<=min)
            min = arr[i];
    }
    cout<<"min:"<<min<<" max:"<<max;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    MaxMin(arr,n);

    return 0;
}