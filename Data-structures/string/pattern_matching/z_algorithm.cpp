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

// core of this algorithm is the function z(k) which computest the
// longest substring(contiguous) starting from k which is also the 
// prefix of that string.

void z_alogrithm(string &str, string &p) {
    // add pattern then $ then str to new string
    string text = p + "$" + str;
    int N = text.length();
    // array to fill the result of z array
    int z_array[N];
    int l=0, r=0;
    z_array[0] = 0;
    // iterating over each element in the string to calculate its z value
    for(int k=1; k<N; k++) {
        // there are 2 cases for each char
        // 1. k can be out of z-box i.e greater than the right boundary
        if(k > r) {
            // possibly starting of z-box
            l = r = k;
            // trying to match the char at right index with the prefix of the string
            while(r < N and text[r]==text[r-l]) {
                r++;
            }
            // find lenght of z-box
            z_array[k] = r-l;
            r--;
        }
        else {
            // 2. k can be in box
            // we are operating inside the z-box

            // tells how far are you form left boundary
            // also the character from the start of string
            // from where you will copy the z value
            int k1 = k-l;
            // if the value doesn't stretch till the right boundary
            // then simply copy the value
            if(text[k1] < r-k+1) {
                z_array[k] = z_array[k1];
            } 
            else {
                // Calculate the z-value of that char instead of copying
                l = r = k; // or l = k
                while(r < N and text[r]==text[r-l]) {
                    r++;
                }
                // find lenght of z-box
                z_array[k] = r-l;
                r--;
            }
        }
    }
    int n = p.length();
    for(int i=0; i<N; i++) {
        if(z_array[i] == n) 
            cout<<i-n-1<<" ";
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    string str, p;
    cin>>str>>p;

    z_alogrithm(str,p);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}