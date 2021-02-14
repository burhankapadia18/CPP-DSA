#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

// Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n
void print_string(int n, char ans[])
{
    if(n == 0)
    {
        cout<<ans<<endl;
        return;
    }

    ans[n-1] = '0';
    print_string(n-1,ans);
    ans[n-1] = '1';
    print_string(n-1,ans);
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    char ans[n];
    print_string(n,ans);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}