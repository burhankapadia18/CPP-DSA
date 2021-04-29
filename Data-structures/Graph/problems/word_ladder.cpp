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

// https://leetcode.com/problems/word-ladder/

int wordLadder(string start, string end, vector<string> &wordList) {
    queue<string> Q;
    Q.push(start);
    int wordsize = start.size();
    unordered_set<string> word;
    for(int i=0; i<wordList.size(); i++)
        word.insert(wordList[i]);
    if(word.find(end) == word.end()) return 0;
    int len = 0;
    while(!Q.empty()) {
        len++;
        int qlen = Q.size();
        for(int i=0; i<qlen; i++) {
            string s = Q.front(); Q.pop();
            for(int j=0; j<wordsize;j++) {
                char org = s[j];
                for(char ch='a'; ch<='z'; ch++) {
                    s[j] = ch;
                    if(s == end) return len+1;
                    if(word.find(s) == word.end()) continue;
                    word.erase(s);
                    Q.push(s);
                }
                s[j] = org;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string start, end_, temp;
    vector<string> wordList;
    cin>>start>>end_;
    while(cin>>temp)
        wordList.push_back(temp);

    cout<<wordLadder(start,end_,wordList);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}