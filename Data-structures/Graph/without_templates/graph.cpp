#include <bits/stdc++.h> 
using namespace std; 

#define vpii vector<pair<int,int> >
#define vi vector<int>
#define ff first
#define ss second

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif
}

void addEdge(vpii adj[], int u, int v, int w, bool dir) 
{ 
	adj[u].push_back(make_pair(v, w)); 
    if(dir)
	    adj[v].push_back(make_pair(u, w)); 
} 
void printGraph(vpii adj[], int n) 
{ 
	int v, w; 
	for (int u = 1; u <= n; u++) 
	{ 
		cout<<u<<" : "; 
		for (auto it:adj[u]) 
		{ 
			v = it.ff; 
			w = it.ss; 
			cout<<"("<<v<<","<<w<<") "; 
		} 
		cout << "\n"; 
	} 
} 

void dfs_util(vpii adj[], bool vis[], int u) {
    vis[u] = 1;
    cout<<u<<" ";
    for(auto i:adj[u])
    {   
        int v = i.ff;
        if(!vis[v])
            dfs_util(adj,vis,v);
    }
}
void dfs(vpii adj[], int n) {
    bool vis[n+1];
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs_util(adj,vis,i);
}

void bfs(vpii adj[], int n) {
    queue<int> Q;
    bool vis[n+1];
    Q.push(1);
    vis[1] = 1;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        cout<<u<<" ";
        for(auto i:adj[u])
        {
            int v = i.ff;
            if(!vis[v]){
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
}

// for directed graph
bool iscyclic_dfs_util(vpii adj[], bool vis[], int u, bool rec[])
{  
    vis[u] = 1;
    rec[u] = 1;
    for(auto i:adj[u])
    {
        int v = i.ff;
        if(!vis[v] && iscyclic_dfs_util(adj,vis,v,rec))
            return 1;
        if(rec[v])
            return 1;
    }
    rec[u] = 0;
    return 0;
}
bool iscyclic_dfs(vpii adj[], int n)
{   
    bool vis[n+1];
    bool rec[n+1];
    for(int i=1; i<=n; n++)
    {   if(!vis[i])
            if(iscyclic_dfs_util(adj,vis,i,rec))
                return 1;
    }
    return 0;
}

// for directed graph
bool iscyclic_bfs(vpii adj[], int n)
{
    vi indegree(n+1,0);
    for(int u=1; u<=n; u++)
        for(auto j:adj[u]){
            int v = j.ff;
            indegree[v]++;
        }
    queue<int> Q;
    for(int i=1; i<=n; i++)
        if(indegree[i]==0)
            Q.push(i);
    int cnt = 0;
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for(auto i:adj[u])
        {
            int v = i.ff;
            if(--indegree[v]==0)
                Q.push(v);
        }
        cnt++;
    }
    if(cnt != n)
        return 1;
    else 
        return 0;
}

// for undirected graph
bool iscyclic_dfs_util_1(vpii adj[], bool vis[], int u, int parent)
{
    vis[u] = 1;
    for(auto i:adj[u])
    {   
        int v = i.ff;
        if(!vis[v])
        {
            if(iscyclic_dfs_util_1(adj,vis,v,u))
                return 1;
        }
        else if(v != parent)
            return 1;
    }
    return 0;
}
bool iscyclic_dfs_1(vpii adj[], int &n)
{
    bool vis[n+1];
    for(int i=1; i<=n; i++)
        if(!vis[i])
            if(iscyclic_dfs_util_1(adj,vis,i,-1))
                return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

	int n, m; 
    cin>>n>>m;
    vpii adj[n+1];
    while(m--)
    {
        int u, v;
        cin>>u>>v;
        addEdge(adj,u,v,1,1);
    }
	// printGraph(adj,n); 
    bfs(adj,n);

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}


