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

int prec(char c)
{
    if(c == '^') return 3;
    if(c == '*' or c == '/') return 2;
    if(c == '+' or c == '-') return 1;
    return -1;
}
string infix2postfix(string &str)
{
    stack<char> S;
    string res = "";
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] >= 'a' and str[i] <='z') // considering only small case letters
            res += str[i];
        else if(str[i] == '(')
            S.push(str[i]);
        else if(str[i] == ')')
        {
            while(S.top() != '(') {
                res += S.top();
                S.pop();
            }
            S.pop();
        }
        else 
        {
            while(!S.empty() and prec(S.top())>prec(str[i])) {
                res += S.top();
                S.pop();
            }
            S.push(str[i]);
        }
    }
    while(!S.empty()) {
        res += S.top(); S.pop();
    }
    return res;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string str;
    cin>>str;
    cout<<infix2postfix(str);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}