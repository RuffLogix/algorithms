#include <bits/stdc++.h>

#define pii pair<int,int>
#define N 1001

using namespace std;

vector<pii> adj[N];
int n,t,b,s;

void solve(){
    int ans=0x3f3f3f3f;
    
    vector<int> dist(n+1 , 0x3f3f3f3f);
    priority_queue<pii , vector<pii> , greater<pii>> q; 
    q.push({0,s});

    while(!q.empty()){
        int u = q.top().second , ww = q.top().first; q.pop();

        if(b-ww<0)continue;
        if(dist[u] <= b-ww)continue;
        dist[u] = b-ww;
        if(u==t){
            ans = min(ans , b-ww);
            continue;
        }
        
        for(auto x : adj[u]){
            int v = x.first , w = x.second;
            q.push({w+ww , v});
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> t;
    int k; cin >> k;
    while(k--){
        int u,v; cin >> u >> v;
        adj[u].push_back({v,0});
    }

    int m; cin >> m;
    while(m--){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    cin >> s >> b;

    solve();

    return 0;
}
/*
5 2
6
3 2
3 5
1 5
3 4
1 2
4 3
4 
3 1 1
4 3 5
5 2 2 
3 4 5
4 9 
*/