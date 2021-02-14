#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > edges;

vector<int> bellmanFord(int src)
{
    vector<int> distance(n+1,INT_MAX);
    distance[src] = 0;
    for(int i=1; i<=n-1; i++)
    {
        for(auto e:edges)
        {
            int u=e[0], v=e[1], w=e[2];
            if(distance[u] < INT_MAX)
                distance[v] = min(distance[v], distance[u]+w);
        }
    }
    return distance;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    cin>>n>>m;
    while(m--)
    {   
        int u, v, w;
        cin>>u>>v>>w;
        vector<int> i;
        i.push_back(u);
        i.push_back(v);
        i.push_back(w);
        edges.push_back(i);
    }

    vector<int> d = bellmanFord(1);
    for(int i=1; i<d.size(); i++)
        cout<<i<<" : "<<d[i]<<endl;

    return 0;
}
