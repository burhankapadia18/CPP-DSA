#include<iostream>
using namespace std;

void subarray_with_given_sum(int a[], int n, int sum){
    int currsum=0;
    /*
    brutefore
    for(int i=0; i<n; i++){
        currsum = 0;
        for(int j=i; j<n; j++){
            currsum += a[j];
            if(currsum == sum){
            cout<<i+1<<" "<<j+1;
            cout<<endl;
            }
        }
    }
    */
    // Optimized 
    int st=0, en=0, i=0, j=0;
    while(j<n && currsum+a[j] <= sum){
        currsum += a[j];
        j++;
    }
    if(sum == currsum){
        cout<<i+1<<" "<<j;
        return;
    }
    while(j<n){
        currsum += a[j];
        while(currsum > sum){
            currsum -= a[i];
            i++;
        }
        if(sum == currsum){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en;
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
    
    int sum;
    cin>>sum;

    subarray_with_given_sum(a,n,sum);
}