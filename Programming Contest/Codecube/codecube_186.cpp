#include <bits/stdc++.h>

using namespace std;

struct edges{
    int v,w;
};

vector<edges> adj[100001];
bool visited[100001];
int dist[100001];

void precompute(int u){
    visited[u] = true;
    for(auto x : adj[u]){
        if(!visited[x.v]){
            dist[x.v] = dist[u]^x.w;
            precompute(x.v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n,m; cin >> n >> m;
    for(int i=0 ; i<n-1 ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dist[1] = 0;
    precompute(1);

    for(int i=0 ; i<m ; i++){
        int a,b; cin >> a >> b;
        int ans = dist[a]^dist[b];
        cout << ans << "\n";
    }
    return 0;
}
