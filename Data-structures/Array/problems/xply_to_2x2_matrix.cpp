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

#define vvi             vector<vector<ll> >


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

void multiply(vvi &mtx1, vvi &mtx2, vvi &res)
{
    int i, j, k;
    loop(i,0,1) {
        loop(j,0,1) {
            res[i][j] = 0;
            loop(k,0,1)
                res[i][j] += mtx1[i][k] * mtx2[k][j];
        }
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    vvi mtx1(2,vi(2)), mtx2(2,vi(2)), res(2,vi(2));
    loop(i,0,1)
        loop(j,0,1)
            cin>>mtx1[i][j];
    loop(i,0,1)
        loop(j,0,1)
            cin>>mtx2[i][j];

    multiply(mtx1,mtx2,res);
    loop(i,0,1) {
        loop(j,0,1)
            cout<<res[i][j]<<'\t';
        cout<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}