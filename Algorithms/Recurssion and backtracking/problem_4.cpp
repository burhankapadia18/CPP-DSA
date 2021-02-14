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

// Generate all the strings of length n drawn from 0... k – 1
void generate_string(char ans[], string &tk, int n)
{
    if(n == 0)
    {
        cout<<ans<<endl;
        return;
    }

    for(int j=0; j<tk.size(); j++)
    {
        ans[n-1] = tk[j];
        generate_string(ans,tk,n-1);
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n;
    cin>>n;
    char ans[n];
    string tk;
    cin>>tk;
    generate_string(ans,tk,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}