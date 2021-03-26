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

// codechef problem, problem code : ICM2003

double f(double x, double b, double c)
{
    return (x*x + b*x + c)/sin(x);
}
int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll t;
    cin>>t;
    while(t--)
    {
        double b,c ;
        cin >> b >> c ;
        double pi = 3.141592653589793238 ;
        double lo = 0 , hi= pi/2.0 , ans = -1 ;
        while(abs(lo-hi) >= 1e-6)
        {
            double m1 = lo + (hi-lo)/3.0 ;
            double m2 = hi - (hi-lo)/3.0 ;
            if(f(m1,b,c) > f(m2,b,c))
            {
                ans = f(m2,b,c) ;
                lo = m1 ;
            }
            else if(f(m1,b,c) < f(m2,b,c))
            {
                ans = f(m1,b,c) ;
                hi = m2 ;
            }
            else
            {
                ans = f(m1,b,c) ;
                lo = m1, hi = m2 ;
            }

        }
        cout << fixed << setprecision(10) << ans << "\n" ;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}