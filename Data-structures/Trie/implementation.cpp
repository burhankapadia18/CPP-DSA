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

class Trie {
    public:
    class node {
        public:
        bool end;
        node *next[26];
        node() {
            end = 0;
            loop(i,0,25) {
                next[i] = NULL;
            }
        }
    };
    node *trie;
    Trie() {
        trie = new node();
    }
    // functions
    void insert(string str) {
        int i = 0;
        node *it = trie;
        while(i<str.size()) {
            if(it->next[str[i]-'a'] == NULL) {
                it->next[str[i]-'a'] = new node();
            }
            it = it->next[str[i]-'a'];
            i++;
        }
        it->end = 1;
    }
    bool search(string str) {
        int i=0;
        node *it = trie;
        while(i<str.size()) {
           if(it->next[str[i]-'a'] == NULL) {
               return 0;
            }
            it = it->next[str[i]-'a'];
            i++; 
        }
        return it->end;
    }
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    Trie *mytrie = new Trie();
    string s;
    while(cin>>s)
        mytrie->insert(s);

    cout<<mytrie->search("burhan")<<endl;
    cout<<mytrie->search("sakina")<<endl;
    cout<<mytrie->search("moiz")<<endl;

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}