#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
// template<typename T>
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define ESPILON         1e-9
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)


void file_i_o()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif
}

int ctr = INT_MAX;

void getMin(int arr[], int &n, int x, int idx, int ctr1, vector<int> &ans, vector<int> ans1)
{
    if(idx >= n)
    {
        if(ctr > ctr1)
        {
            ctr = ctr1;
            ans = ans1;
        }
        return;
    }
    loop(i,1,x)
    {
        getMin(arr,n,x-i,idx+i,ctr1,ans,ans1);
    }
    x += arr[idx];
    ans1.push_back(idx);
    loop(i,1,x)
    {
        getMin(arr,n,x-i,idx+i,ctr1+1,ans,ans1);
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;
        int arr[n];
        loop(i,0,n-1)
            cin>>arr[i];

        vector<int> ans, ans1;
        getMin(arr,n,x,0,0,ans,ans1);
        cout<<ctr<<endl;
        for(auto i:ans)
            cout<<i<<" ";
        cout<<endl;
        ctr = INT_MAX;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}