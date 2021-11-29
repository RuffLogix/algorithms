#include <bits/stdc++.h>

#define levels 20
using namespace std;

vector<int> adj[30001];
int parent[30001][levels];
int depth[30001];

void dfs(int u,int p){
    depth[u] = depth[p]+1;
    parent[u][0] = p==0 ? -1 : p;

    for(auto v : adj[u]){
        if(parent[v][0]==0){
            dfs(v,u);
        }
    }
}

void preprocess(){
    for(int j=1 ; j<levels ; j++){
        for(int i=1 ; i<30001 ; i++){
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int lca(int u,int v){
    if(depth[u] < depth[v])swap(u,v);

    int diff = depth[u] - depth[v];

    for(int i=0 ; i<levels ; i++){
        if((diff>>i)&1){
            v = parent[v][i];
        }
    }

    if(u==v)return u;

    for(int i=levels-1 ; i>=0 ; i--){
        if(parent[u][i]!=parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;
    for(int i=0 ; i<n-1 ; i++){
        int u,v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    int m; cin >> m;
    int pre; cin >> pre;
    int ans=0;
    for(int i=0 ; i<m-1 ; i++){
        int x; cin >> x;
        int dist=depth[lca(pre,x)];
        ans += (depth[x]+depth[pre])-dist*2;
        pre = x;
    }

    cout << ans;

    return 0;
}
/*
5
1 2
1 5
3 5
4 5
4
1
3
2
5
*/
