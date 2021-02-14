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

/*
Question :-
You have a grid of characters, also you have a word given.
check if the word exists in the grid, in the grid we can construct the word
by taking any adjacent non-diagonal edge, the same letter from the word 
shouldn't be used twice.
        A B C E             search -> ABCCED
        S F C S
        A D E E

(m,n) <= 2x10^2
word <= 10^3
*/

bool isSafe(vector<vector<char> > &grid, ll n, ll m, ll i, ll j)
{
    return (i>=0 && j>=0 && i<n && j<m && grid[i][j]!='$');
}
bool word_search_util(vector<vector<char> > &grid, ll n, ll m, string &word,ll r, ll c, ll idx)
{
    if(idx == word.length())
        return 1;
    if(grid[r][c] != word[idx])
        return 0;

    ll xdir[] = {-1,1,0,0};
    ll ydir[] = {0,0,1,-1};

    grid[r][c] = '$';
    loop(k,0,3)
    {
        if(isSafe(grid,n,m,r+xdir[k],c+ydir[k]))
            if(word_search_util(grid,n,m,word,r+xdir[k],c+ydir[k],idx+1))
                return 1;
    }
    grid[r][c] = word[idx];

    return 0;
}
bool word_search(vector<vector<char> > &grid, ll n, ll m, string &word)
{
    loop(i,0,n-1)
        loop(j,0,m-1)
        {   
            if(grid[i][j] == word[0] && word_search_util(grid,n,m,word,i,j,0))
                return 1;
        }
    return 0;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    vector<vector<char> > grid(3,vector<char> (4,'A'));
    string word;

    loop(i,0,2)
        loop(j,0,3)
            cin>>grid[i][j];
    cin>>word;

    cout<<word_search(grid,3,4,word);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}