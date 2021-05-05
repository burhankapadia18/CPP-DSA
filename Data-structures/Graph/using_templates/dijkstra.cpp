#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph {
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

    void getPath(T i, map<T,T> &par, map<T,int> &d) {

        if(d[i] == INT_MAX) {
            cout<<"no path";
            return;
        }
        if(par[i] == i) {
            cout<<i<<"->";
            return;
        }

        getPath(par[i],par,d);
        cout<<i<<"->";
    }
    void dijsktra(T src) {
        set<pair<int,T> > S;
        map<T,int> distance;
        map<T,T> parent;
        for(auto i:adj)
            distance[i.first] = INT_MAX;
        distance[src] = 0;
        parent[src] = src;
        S.insert(make_pair(0,src));
        while(!S.empty()) {
            auto it = S.begin();
            T i = it->second;
            S.erase(it);
            for(auto e:adj[i]) {
                T nb = e.first;
                int w = e.second;
                if(distance[i]+w < distance[nb]) {
                    parent[nb] = i;
                    S.erase(make_pair(distance[nb],nb));
                    distance[nb] = distance[i] + w;
                    S.insert(make_pair(distance[nb],nb));
                }
            }
        }
        for(auto i:distance)
            cout<<i.first<<" : "<<i.second<<endl;
        for(auto i:adj) {
            cout<<i.first<<" : ";
            getPath(i.first,parent,distance);
            cout<<endl;
        }
    }
};

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    graph<int> g;

    int edges; 
    cin>>edges;
    while(edges--) {
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w,1);
    }

    g.dijsktra(1);

    return 0;
}