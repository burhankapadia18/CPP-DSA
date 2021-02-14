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

void print_adj(vector<pair<int,int> >  adj[], int n)
{
    for(int u=1; u<=n; u++)
    {   
        cout<<u<<":";
        for(auto v:adj[u])
        {
            cout<<"("<<v.first<<","<<v.second<<")";
        }
        cout<<'\n';
    }
}

void Prims(vector<pair<int,int> > adj[], int n, int src)
{
    set<pair<int,int> > s;
    vector<int> distance(n+1,-1);
    vector<int> path(n+1);
    distance[src] = 0;
    path[src] = src;
    s.insert(make_pair(distance[src],src));
    while(!s.empty())
    {
        auto i = s.begin();
        int u = i->second;
        int w = i->first;
        s.erase(i);
        for(auto j:adj[u])
        {
            int new_distance = distance[u] + w;
            if(distance[j.first] == -1)
            {
                distance[j.first] = w;
                s.insert(make_pair(distance[j.first],j.first));
                path[j.first] = u;
            }
            if(distance[j.first] > new_distance)
            {
                s.erase(make_pair(distance[j.first],j.first));
                distance[j.first] = w;
                s.insert(make_pair(distance[j.first],j.first));
                path[j.first] = u;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    int n, m;
    cin>>n>>m;
    vector<pair<int,int> >  adj[n+1];
    while(m--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    print_adj(adj,n);
    Prims(adj,n,1);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}