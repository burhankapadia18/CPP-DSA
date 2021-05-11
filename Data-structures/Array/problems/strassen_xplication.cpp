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
// #define vi              vector<ll>
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

/*
    a  b     e  f         p5+p4-p2+p6   p1+p2
         X         =
    c  d     g  h         p3+p4         p1+p5-p3-p7

    p1 = a(f-h)
    p2 = (a+b)h
    p3 = (c+d)e
    p4 = d(g-e)
    p5 = (a+d)(e+h)
    p6 = (b-d)(g+h)
    p7 = (a-c)(e+f)
*/
#define vvi             vector<vector<int> >
#define vi              vector<int>
vvi add(vvi &a, vvi &b) {
    int n = a.size();
    vvi ans(n,vi(n));
    loop(i,0,n-1) {
        loop(j,0,n-1) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    return ans;
}
vvi sub(vvi &a, vvi &b) {
    int n = a.size();
    vvi ans(n,vi(n));
    loop(i,0,n-1) {
        loop(j,0,n-1) {
            ans[i][j] = a[i][j] - b[i][j];
        }
    }
    return ans;
}
vvi split(vvi &a, int str, int enr, int stc, int enc) {
    int n = a.size();
    vvi ans(n/2,vi(n/2));
    int i=0, j=0;
    loop(r,str,enr) {
        j = 0;
        loop(c,stc,enc) {
            ans[i][j] = a[r][c];
            j++;
        }
        i++;
    }
    return ans;
}
vvi strassen(vvi &M1, vvi &M2) {

    if(M1.size() == 1) {
        vvi ans(1,vi(1));
        ans[0][0] = M1[0][0] * M2[0][0];
        return ans;
    }
    int n = M1.size();

    if(n%2 != 0) {
        // if matrix size is odd
        M1.resize(n+1,vi (n,0));
        M2.resize(n+1,vi (n,0));
        loop(i,0,n) {
            M1[i].resize(n+1,0);
            M2[i].resize(n+1,0);
        }
        n++;
    }

    vvi a = split(M1,0,(n/2)-1,0,(n/2)-1);
    vvi b = split(M1,0,(n/2)-1,n/2,n-1);
    vvi c = split(M1,n/2,n-1,0,(n/2)-1);
    vvi d = split(M1,n/2,n-1,n/2,n-1);
    vvi e = split(M2,0,(n/2)-1,0,(n/2)-1);
    vvi f = split(M2,0,(n/2)-1,(n/2),n-1);
    vvi g = split(M2,n/2,n-1,0,(n/2)-1);
    vvi h = split(M2,n/2,n-1,n/2,n-1);

    vvi temp, temp_;

    temp = sub(f,h);
    vvi p1 = strassen(a,temp);
    temp = add(a,b);
    vvi p2 = strassen(temp,h);
    temp = add(c,d);
    vvi p3 = strassen(temp,e);
    temp = sub(g,e);
    vvi p4 = strassen(d,temp);
    temp = add(a,d); temp_ = add(e,h);
    vvi p5 = strassen(temp,temp_);
    temp = sub(b,d); temp_ = add(g,h);
    vvi p6 = strassen(temp,temp_);
    temp = sub(a,c); temp_ = add(e,f);
    vvi p7 = strassen(temp,temp_);

    temp = add(p5,p4); temp_ = add(p2,p6);
    vvi Q1 = sub(temp,temp_);
    vvi Q2 = add(p1,p2);
    vvi Q3 = add(p3,p4);
    temp = add(p1,p5); temp_ = sub(p3,p7);
    vvi Q4 = sub(temp,temp_);

    vvi ans(n,vi(n));
    for(int i=0; i<n/2; i++) {
        for(int j=0; j<n/2; j++) {
            ans[i][j] = Q1[i][j];
            ans[i][j+(n/2)] = Q2[i][j];
            ans[i+(n/2)][j] = Q3[i][j];
            ans[i+(n/2)][j+(n/2)] = Q4[i][j];  
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
    vvi a(n,vi(n)), b(n,vi(n));
    loop(i,0,n-1)
        loop(j,0,n-1)
            cin>>a[i][j];
    loop(i,0,n-1)
        loop(j,0,n-1)
            cin>>b[i][j];

    vvi c = strassen(a,b);

    for(auto i:c) {
        for(int j:i) {
            cout<<j<<'\t';
        }
        cout<<endl;
    }

    

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}