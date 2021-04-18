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

class node {
    public:
    char data;
    int freq;
    node *left;
    node *right;
    node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};
class Compare {
public:
    bool operator()(node* a, node* b) {
        return a->freq > b->freq;
    }
};
void printHuffman(node *root, string ans) {
    if(root->left)
        printHuffman(root->left,ans+"0");
    if(root->right)
        printHuffman(root->right,ans+"1");
    if(!root->left and !root->right) {
        cout<<root->data<<":"<<ans<<endl;
    }
}
void huffmanCodes(char ch[], int freq[], int n) {
    priority_queue<node*,vector<node*>,Compare> pq;
    for (int i = 0; i < n; i++) {
        node* newNode = new node(ch[i], freq[i]);
        pq.push(newNode);
    }
    while(pq.size() != 1) {
        node *left = pq.top(); 
        pq.pop();
        node *right = pq.top(); 
        pq.pop();
        node *root = new node('$',left->freq+right->freq);
        root->left = left;
        root->right = right;
        pq.push(root);
    }
    node *root = pq.top(); pq.pop();
    printHuffman(root,"");
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    char ch[n]; int freq[n];
    loop(i,0,n-1)
        cin>>ch[i];
    loop(i,0,n-1)
        cin>>freq[i];

    huffmanCodes(ch,freq,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}