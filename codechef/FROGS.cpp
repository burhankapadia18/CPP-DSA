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
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
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
        ll n;
        cin>>n;
        vi weight(n+1), lenght(n+1);
        ll x;
        loop(i,1,n)
        {   
            cin>>x;
            weight.push_back(x);
        }
        loop(i,1,n)
        {   
            cin>>x;
            lenght.push_back(x);
        }
        mp<ll,ll> ind;
        ll s = 0;
        loop(i,1,n)
            ind[i] = weight[i];
        loop(i,2,n)
        {
            ll temp1 = weight[i];
            ll temp2 = weight[i-1];
            ll temp = 0;
            if(temp1 <= temp2)
            {   // calculating ceiling value
                // temp = (ll)(temp2+1-temp1) / lenght[temp1];
                if(((temp2+1-temp1) % lenght[temp1]) != 0)
                    temp += 1;
            }
            s += temp;
            weight[i] += (temp*lenght[temp1]);
        }
        cout<<s<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}