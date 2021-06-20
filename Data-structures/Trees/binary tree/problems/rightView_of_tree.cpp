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

// ************************************************************************
class node {
	public:
	int data;
	int hd;
	node *left;
	node *right;
	node(int info) {
		data = info;
		left = right = NULL;
	}
};
node *buildBinaryTreeUtil(int *in, int *pr, int inS, int inE, int prS, int prE) {
	if(inS > inE)
		return NULL;
	node *root = new node(pr[prS]);
	int rootIndex = -1;
	for(int i=inS; i<=inE; i++) {
		if(in[i] == root->data) {
			rootIndex = i;
			break;
		}
    }
	int LinS = inS;
	int LinE = rootIndex-1;
	int RinS = rootIndex+1;
	int RinE = inE;
	int LprS = prS+1;
	int LprE = LinE-LinS+LprS;
	int RprS = LprE+1;
	int RprE = prE;
	root->left = buildBinaryTreeUtil(in,pr,LinS,LinE,LprS,LprE);
	root->right = buildBinaryTreeUtil(in,pr,RinS,RinE,RprS,RprE);
	return root;
}
node *builTree(int *in, int *pr, int size) {
	return buildBinaryTreeUtil(in,pr,0,size-1,0,size-1);
}
void deleteTree(node *root) {
	if(!root)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete(root);
}
// ************************************************************************

// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

vector<int> rightView(node *root) {
    vector<int> ans;
    if(!root)
		return ans;
	node *temp = root;
	queue <node*> Q;
	Q.push(temp);
	Q.push(NULL);
	while(!Q.empty()) {
		temp = Q.front(); Q.pop();
		if(temp == NULL) {
			if(!Q.empty())
				Q.push(NULL);
		}
		else {
			if(Q.front() == NULL)
				ans.push_back(temp->data);
			if(temp->left) Q.push(temp->left);
			if(temp->right) Q.push(temp->right);
		}
	}
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    int in[n], pr[n];
    loop(i,0,n-1) cin>>in[i];
    loop(i,0,n-1) cin>>pr[i];
    node *root = builTree(in,pr,n);

    vector<int> ans = rightView(root);
    for(int i:ans)
        cout<<i<<" ";

    deleteTree(root);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}