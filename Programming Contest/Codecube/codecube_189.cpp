#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

vector<pii> adj[100001];
int n,m,s,t; 

int solve(){
    priority_queue<pair<int,pii> , vector<pair<int,pii>> , greater<pair<int,pii>>> q;
    vector<int> dist(n+1 , 1e12);

    q.push({0,{-0x3f3f3f3f,s}});
    
    int mn=0x3f3f3f3f;
    while(!q.empty()){
        int u = q.top().second.second , mxw = q.top().second.first , uw = q.top().first; q.pop();

        if(dist[u] <= uw-mxw)continue;
        dist[u] = uw-mxw;

        if(u==t){
            mn = min(mn,uw-max(mxw,0));
            continue;
        }

        for(auto x : adj[u]){
            q.push({uw+x.second , {max(mxw,x.second) , x.first}});
        }
    }

    return mn;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> m >> s >> t;

    int W=0;
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        W+=w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << W-solve();

    return 0;
}
