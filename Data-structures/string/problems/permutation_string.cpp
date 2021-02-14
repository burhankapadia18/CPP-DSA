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

void permutation(string s, string ans) 
{
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<s.length(); i++)
    {
        char c = s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        permutation(ros,ans+c);
    }
}

void permutation(string &str, int idx)
{
    if(idx == str.size())
    {
        cout<<str<<endl;
        return;
    }

    for(int i=idx; i<str.size(); i++)
    {
        swap(str[idx],str[i]);
        permutation(str,idx+1);
        swap(str[idx],str[i]);
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    string str = "ABC";
    permutation(str,0);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}