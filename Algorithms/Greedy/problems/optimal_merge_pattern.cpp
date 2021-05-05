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

int minComputation(int files[], int n) {
	priority_queue<int, vector<int>, greater<int>> pq;
	loop(i,0,n-1) {	
		pq.push(files[i]);
	}
	int count = 0;
	while(pq.size()>1){
		int first_smallest = pq.top();
		pq.pop();
		int second_smallest = pq.top();
		pq.pop();
		int temp = first_smallest + second_smallest;
		count += temp;
		pq.push(temp);
	}
	return count;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
	int files[n];
    loop(i,0,n-1)
        cin>>files[i];

	cout<<"Minimum Computations = "<<minComputation(files,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}

// Function to find minimum computation
int minComputation(int size, int files[])
{
	
	// Create a min heap
	priority_queue<int, vector<int>,
		greater<int>> pq;

	for(int i = 0; i < size; i++)
	{
		
		// Add sizes to priorityQueue
		pq.push(files[i]);
	}
	
	// Variable to count total Computation
	int count = 0;

	while(pq.size() > 1)
	{
		
		// pop two smallest size element
		// from the min heap
		int first_smallest = pq.top();
		pq.pop();
		int second_smallest = pq.top();
		pq.pop();
		
		int temp = first_smallest + second_smallest;

		// Add the current computations
		// with the previous one's
		count += temp;

		// Add new combined file size
		// to priority queue or min heap
		pq.push(temp);
	}
	return count;
}