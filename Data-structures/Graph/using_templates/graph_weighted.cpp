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

    void bfs(T u) {
        map<T,bool> visited;
        queue<T> Q;
        Q.push(u);
        while(!Q.empty()){
            u = Q.front(); Q.pop();
            if(!visited[u]){
                cout<<u<<" ";
                visited[u] = 1;
            }
            for(auto a:(adj[u])){
                if(!visited[a.first])
                    Q.push(a.first);
            }
        }
    }

    void dfs_util(T u, map<T,bool> &vis){
        vis[u] = 1;
        cout<<u<<" ";
        for(auto a:(adj[u])){
            if(!vis[a.first])
                dfs_util(a.first,vis);
        }
    }
    void dfs(T u){
        map<T,bool> vis;
        dfs_util(u,vis);
    }

    bool iscyclic_dfs_util(T u, map<T,bool> &vis, map<T,bool> &rec) {

        if(!vis[u]){
            vis[u] = 1;
            rec[u] = 1;
        
            for(auto a:adj[u]){
                if(!vis[a.first])
                    if(iscyclic_dfs_util(a.first,vis,rec))
                        return 1;
                else if(rec[a.first])
                    return 1;
            }
        }

        rec[u] = 0;
        return 0;
    }
    bool iscyclic_dfs(){
        // works only for directed graph
        map<T,bool> vis;
        map<T,bool> rec;
        for(auto i:adj) {
            vis[i.first] = 0;
            rec[i.first] = 0;
        }
        
        for(auto i:adj)
            if(iscyclic_dfs_util(i.first,vis,rec))
                return 1;
        return 0;
    }

    bool iscyclic_bfs(){
        // works only for directed graph
        // using topological sort

        map<T,int> indegree;
        for(auto u:adj)
            indegree[u.first] = 0;
        for(auto u:adj)
            for(auto v:u.second)
                indegree[v.first]++;
        queue<T> Q;
        for(auto i:indegree)
            if(indegree[i.first]==0)
                Q.push(i.first);
        int cnt = 0;
        //vector<T> topilogical_order;
        while(!Q.empty()){
            T u = Q.front(); Q.pop();
            // topilogical_order.push_back(u);
            for(auto n:adj[u])
                if(--indegree[n.first]==0)
                    Q.push(n.first);
            cnt++;
        }
        if(cnt != adj.size())
            return 1;
        else 
            return 0;
    }

};

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif

    graph<int> g;

    int n, m; 
    cin>>n>>m;
    while(m--) {
        int u, v, bidir;
        cin>>u>>v>>bidir;
        g.addEdge(u,v,1,0);
    }

    g.print_adj();
    cout<<g.iscyclic_dfs();

    return 0;
}