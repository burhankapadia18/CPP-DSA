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

/*
Merge Intervals
https://leetcode.com/problems/merge-intervals/
5
1 2, 2 4, 5 8, 7 10, 11 12
*/

// tc:O(nlogn)   sc:O(n)
void mergeIntervals(vector<pii> &arr)
{   
    sort(arr.begin(),arr.end());
    stack<pii> S;
    S.push(arr[0]);
    int n = arr.size();
    loop(i,1,n-1)
    {
        ll s = S.top().ff, e = S.top().ss;
        ll s_ = arr[i].ff, e_ = arr[i].ss;
        if(e >= s_)
        {
            S.pop();
            if(e > e_)
                S.push(make_pair(s,e));
            else   
                S.push(make_pair(s,e_));
        }
        else 
            S.push(make_pair(s_,e_));
    }
    while(!S.empty())
    {
        cout<<S.top().ff<<" "<<S.top().ss<<endl;
        S.pop();
    }
}

// tc:O(nlogn)   sc:O(1)
void mergeIntervals_(vector<pii> &arr)
{
    sort(arr.begin(),arr.end());
    int idx = 0;
    int n = arr.size();
    loop(i,1,n-1)
    {
        if(arr[idx].ss >= arr[i].ff)
        {
            if(arr[idx].ss < arr[i].ss)
                arr[idx].ss = arr[i].ss;
        }
        else 
        {
            idx++;
            swap(arr[idx],arr[i]);
        }
    }
    loop(i,0,idx)
        cout<<arr[i].ff<<" "<<arr[i].ss<<endl;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll n;
    cin>>n;
    vector<pii> arr;
    while(n--)
    {
        ll x, y;
        cin>>x>>y;
        arr.push_back(make_pair(x,y));
    }
    mergeIntervals_(arr);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}