#include<bits/stdc++.h>
using namespace std;
template<typename T>


class graph 
{
public:
    map<T, vector<T> > adj;
    void addEdge(int u, int v, bool dir) 
    {
        adj[u].push_back(v);
        if(dir)
            adj[v].push_back(u);
    }
    void print_adj()
    {
        for(auto i:adj){
            cout<<i.first<<": ";
            for(auto j:i.second)
                cout<<j<<",";
            cout<<endl;
        }
    }
    void topologicalSort()
    {
        map<T,int> indegree;
        for(auto u:adj)
            indegree[u.first] = 0;
        for(auto u:adj)
            for(auto v:u.second)
                indegree[v]++;
        queue<T> Q;
        for(auto i:indegree)
            if(indegree[i.first]==0)
                Q.push(i.first);
        int cnt = 0;
        vector<T> topological_order;
        while(!Q.empty())
        {
            T u = Q.front(); Q.pop();
            topological_order.push_back(u);
            for(auto n:adj[u])
                if(--indegree[n]==0)
                    Q.push(n);
            cnt++;
        }
        if(cnt != adj.size())
        {
            cout<<"graph has cycle!!!";
            return;
        }
        else    
            for(auto i:topological_order)
                cout<<i<<" ";
    }
};

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    graph<int> G;
    int edges;
    cin>>edges;
    while(edges--)
    {
        int u, v;
        bool dir;
        cin>>u>>v>>dir;
        G.addEdge(u,v,dir);
    }
    G.print_adj();
    G.topologicalSort();

    return 0;
}
