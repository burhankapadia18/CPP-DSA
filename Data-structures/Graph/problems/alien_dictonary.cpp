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

void solve(vector<string> &words)
{
    ump<char,vector<char> > adjlist;
    ump<char,int> indegree;
    for(auto word:words)
        for(auto ch:word)
        {
            adjlist[ch];
            indegree[ch] = 0;
        }
    int i=0, j=1;
    while(j<words.size())
    {
        for(int k=0; k<words[i].length() && k<words[j].length(); k++)
            if(words[i][k] != words[j][k])
            {
                adjlist[words[i][k]].push_back(words[j][k]);
                break;
            }
        i++; j++;
    }
    int n = adjlist.size();
    for(auto i:adjlist)
        for(auto j:i.ss)
            indegree[j]++; 
    queue<char> Q;
    for(auto i:indegree)
        if(i.ss == 0)
            Q.push(i.ff);
    string ans = "";
    while(!Q.empty())
    {
        char ch = Q.front(); Q.pop();
        ans += ch;
        for(auto i:adjlist[ch])
        {
            if(--indegree[i] == 0)
                Q.push(i);
        }
    }
    if(ans.length() != n)
        cout<<"";
    else 
        cout<<ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    vector<string> words;
    string str;
    while(cin>>str)
        words.push_back(str);

    solve(words);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}