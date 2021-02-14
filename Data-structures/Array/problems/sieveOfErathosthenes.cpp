#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

void sieve(vector<int> &arr, int n)
{
    for(int i=2; i<=n; i++)
    {
        if(arr[i] == 0)
        {
            for(int j=i*i; j<=n; j+=i)
                arr[j] = 1;
        }
    }

    for(int i=2; i<=n; i++)
        if(arr[i] == 0)
            cout<<i<<" ";
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    sieve(arr,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}