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

// https://www.spoj.com/problems/CPCRC1C/

ll pow10(int p) {
    ll result = 1;
    loop(i,1,p)
        result *= 10;
    return result;
}
ll sumOfDigits(int num) {
    if(num/10 == 0) 
        return (num*(num+1))/2;
    ll result = 0;
    string s = to_string(num);
    int n = s.size();
    int pown_1 = pow10(n-1);
    int first = num/pown_1;
    int sum = pow10(n-2)*45*(n-1);
    loop(i,0,first-1) {
        result = result + (i*pown_1) + sum;
    }
    int restOfNum = num%pown_1;
    result += first*(restOfNum+1);
    result += sumOfDigits(restOfNum);
    return result;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    ll a, b;
    while(1) {
        cin>>a>>b;
        if(a == -1 and b== -1)
            break;
        cout<<sumOfDigits(b)-sumOfDigits(a-1)<<endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}