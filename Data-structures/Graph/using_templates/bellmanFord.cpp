#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph 
{   
    public:
    map<T,vector<pair<T,int> > > adj;

    void addEdge(T u, T v, int wt, bool bidir) {
        adj[u].push_back(make_pair(v,wt));
        if(bidir)
            adj[v].push_back(make_pair(u,wt));
    }
    void print_adj() {
        for(auto n:adj){
            cout<<n.first<<" : ";
            for(auto a:n.second){
                cout<<"("<<a.first<<","<<a.second<<") ";
            }
            cout<<endl;
        }
    }

    void bellmanFord(T src)
    {   
        // not working (small bug)
        queue<T> Q; 
        map<T,int> distance;
        map<T,T> parent;
        for(auto i:adj)
            distance[i.first] = INT_MAX;
        distance[src] = 0;
        //distance[4] = INT_MAX;
        parent[src] = src;
        Q.push(src);
        while(!Q.empty())
        {
            T node = Q.front(); Q.pop();
            for(auto i:adj[node])
            {
                T nb = i.first;
                int w = i.second;
                int newDistance = distance[node] + w;
                if(distance[nb] >= newDistance)
                {
                    distance[nb] = newDistance;
                    parent[nb] = node;
                    Q.push(nb);
                }
            }
        }
        for(auto i:distance)
            cout<<i.first<<" : "<<i.second<<endl;
    }
};

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    graph<int> g;
    int n,edges;
    cin>>n>>edges;
    while(edges--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w,0);
    }

    // g.print_adj();
    g.bellmanFord(1);


    return 0;
}
