#include <bits/stdc++.h>

using namespace std;

vector<int> adj[500001];
int disc[500001] , low[500001];
bitset<500001> visited;
int anss=0x3f3f3f3f;
int cnt=0;
int mx=-0x3f3f3f3f;

int solve(int u,int p){
    visited[u] = true;
    low[u] = disc[u] = cnt++;
    int node_=1 , art_node=0;

    for(auto v : adj[u]){
        if(!visited[v]){
            int tmp = solve(v,u);
            node_ += tmp;
            low[u] = min(low[u] , low[v]);
            if((p!=-1 && low[v] >= disc[u])){
                art_node+=tmp;
            }
        }else if(v!=p){
            low[u] = min(low[u] , disc[v]);
        }
    }

    if(art_node && mx<=art_node){
        if(mx==art_node)anss=min(anss,u);
        else anss = u;
        mx = art_node;
    }

    return node_;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int N,S; cin >> N >> S;

    for(int i=0 ; i<N ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(S,-1);

    if(mx==-0x3f3f3f3f){
        if(S==1) cout << 2 << "\n" << 0;
        else cout << 1 << "\n" << 0;
    }else{
        cout << anss << "\n";
        cout << mx;
    }
    return 0;
}
