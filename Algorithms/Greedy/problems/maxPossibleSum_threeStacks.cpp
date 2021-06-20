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

// https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/


int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n1, n2, n3;
    cin>>n1>>n2>>n3;
    int s1[n1], s2[n2], s3[n3];
    loop(i,0,n1-1) cin>>s1[i];
    loop(i,0,n2-1) cin>>s2[i];
    loop(i,0,n3-1) cin>>s3[i];

    int sum1=0, sum2=0, sum3=0;
    loop(i,0,n1-1) sum1 += s1[i];
    loop(i,0,n2-1) sum2 += s2[i];
    loop(i,0,n3-1) sum3 += s3[i];
    int t1=0, t2=0, t3=0;
    int ans=0;
    while(t1<n1 and t2<n2 and t3<n3) {
        if(sum1 == sum2 and sum2 == sum3) {
            ans = sum1;
            break;
        }
        if(sum1 >= sum2 and sum1>=sum3) {
            sum1 -= s1[t1++];
        }
        else if(sum2 >= sum1 and sum2 >= sum3) {
            sum2 -= s2[t2++];
        }
        else if(sum3 >= sum1 and sum3 >= sum2) {
            sum3 -= s3[t3++];
        }
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}