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
Given a number n, find integer part of the squareroot of the number.
*/
int squareRoot_integer(int n)
{
    int lo = 1, hi = n-1;
    int ans = -1;
    while(lo <= hi)
    {
        int mi = mid(lo,hi);
        if(mi*mi == n)
            return mi; // perfect square
        else if(mi*mi > n)
            hi = mi - 1;
        else 
        {   
            ans = mi;
            lo = mi + 1;
        }
    }
    return ans;
}

/*
Given a  +ve integer n, find the square root of the number upto 
k decimal places.
*/
float squareRoot(int n, int precision)
{   // integral part
    int lo = 1, hi = n-1;
    float ans = -1;
    while(lo <= hi)
    {
        int mi = mid(lo,hi);
        if(mi*mi == n) {
            ans = mi;
            break;
        }
        else if(mi*mi > n)
            hi = mi - 1;
        else 
        {   
            ans = mi;
            lo = mi + 1;
        }
    }
    // fractional part
    float increment = 0.1;
    loop(i,1,precision)
    {
        while(ans*ans <= n)
            ans += increment;
        ans -= increment;
        increment /= 10;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n,k;
    cin>>n>>k;
    cout<<squareRoot_integer(n)<<endl;
    float ans = squareRoot(n,k);
    cout<<fixed<<setprecision(k)<<ans<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}