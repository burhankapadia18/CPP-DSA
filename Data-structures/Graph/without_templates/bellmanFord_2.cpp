#include<bits/stdc++.h>
using namespace std;

// using edge list
vector<int> bellmanFord(vector<vector<int> > &edges, int src, int n, int m)
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

// using adj list
vector<int> bellmanFord_(vector<pair<int,int> > adjlist[], int n, int src) 
{
    vector<int> distance(n+1,INT_MAX);
    vector<int> path(n+1);
    queue<int> Q;
    vector<bool> inQueue(n+1,0);
    distance[src] = 0;
    path[src] = src;
    Q.push(src);
    inQueue[src] = 1;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inQueue[u] = 0;
        for(auto i:adjlist[u])
        {
            int v = i.first;
            int w = i.second;
            int newDistance = distance[u] + w;
            if(newDistance < distance[v])
            {
                distance[v] = newDistance;
                path[v] = u;
                if(!inQueue[v]) {
                    Q.push(v);
                    inQueue[v] = 1;
                }
            }
        }
    }
    return distance;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<vector<int> > edges;
    vector<pair<int,int> > adjlist[n+1];
    while(m--)
    {   
        int u, v, w;
        cin>>u>>v>>w;

        // vector<int> i;
        // i.push_back(u);
        // i.push_back(v);
        // i.push_back(w);
        // edges.push_back(i);

        adjlist[u].push_back(make_pair(v,w));
        // if undirected
        // adjlist[v].push_back(make_pair(u,w));
    }

    vector<int> d = bellmanFord_(adjlist,n,1);
    for(int i=1; i<d.size(); i++)
        cout<<i<<" : "<<d[i]<<endl;

    return 0;
}
