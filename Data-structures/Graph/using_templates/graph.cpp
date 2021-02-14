#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph {
public:
    map<T, vector<T> > adj;
    void add_edge(T v1, T v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    void print_adj() {
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second)
                cout<<j<<",";
            cout<<endl;
        }
    }
    
    void dfs_util(T u, map<T,bool> &vis) {
        vis[u] = 1;
        cout<<u<<" ";
        for(auto i:adj[u])
            if(!vis[i])
                dfs_util(i,vis);
    }
    void dfs() {
        map<T,bool> vis;
        auto u = adj.begin();
        dfs_util(u->first,vis);
    }

    void bfs() {
        map<T,bool> vis;
        queue<T> Q;
        auto u = adj.begin()->first;
        Q.push(u);
        while(!Q.empty()){
            u = Q.front(); Q.pop();
            if(!vis[u]){
                cout<<u<<" ";
                vis[u] = 1;
            }
            for(auto i:adj[u]){
                if(!vis[i])
                    Q.push(i);
            }
        }
    }

    bool iscyclic_dfs_util(int v, map<T,bool> vis, int parent) {
        vis[v] = 1; 
        for (auto i:adj[v]) {
            if (!vis[i]) { 
                if (iscyclic_dfs_util(i, vis, v)) 
                    return 1; 
            } 
            else if (i != parent) 
                return 1; 
        } 
        return 0; 
    }
    bool iscyclic_dfs() {
        // works only for undirected graph

        map<T,bool> visited; 
    
        for (auto u:adj) 
        { 
            if (!visited[u.first])  
                if (iscyclic_dfs_util(u.first, visited, -1)) 
                    return 1; 
        } 
        return 0; 
    }

    bool iscyclic_bfs() {
        // works only for undirected graph

        map<T,bool> vis;
        map<T,int> parent;
        queue<T> Q;
        auto src = adj.begin()->first;
        Q.push(src);
        vis[src] = 1;
        parent[src] = src;

        while(!Q.empty()) {
            T node  = Q.front(); Q.pop();
            for(T i:adj[node]) {
                if(vis[i] && parent[node]!=i)
                    return 1;
                else if(!vis[i]) {
                    vis[i] = 1;
                    parent[i] = node;
                    Q.push(i);
                }
            }
        }
        return 0;
    }

    void shortestpath_bfs(T src, T des) {
        map<T,T> parent;
        map<T,bool> vis;
        map<T,int> distance;
        for(auto i:adj) 
            distance[i.first] = -1;
        queue<T> Q;
        Q.push(src);
        parent[src] = src;
        distance[src] = 0;
        while(!Q.empty()){
            T node = Q.front(); Q.pop();
            vis[node] = 1;
            for(T neighbour:adj[node]) {
                if(distance[neighbour] == -1){
                    parent[neighbour] = node;
                    distance[neighbour] = distance[node]+1;
                    Q.push(neighbour);
                }
            }
        }
        //for(auto i:adj) 
        //    cout << "distance to " << i.first<< " from  " << src << " is " << distance[i.first] << endl;
        
        // if destination is given 
        int dis = 0;
        while(parent[des] != des) {
            cout<<des<<"<--";
            des = parent[des];
            dis++;
        } cout<<src<<"\ndistance="<<dis<<endl;
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
    while(edges--){
        int u,v;
        cin>>u>>v;
        g.add_edge(u,v);
    }
    cout<<g.iscyclic_dfs();

    return 0;
}