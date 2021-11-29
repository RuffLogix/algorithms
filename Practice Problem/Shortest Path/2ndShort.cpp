#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

int solve(int v , vector<pii> adj[] , int s , int t){
    priority_queue<pii , vector<pii> , greater<pii>> q;

    q.push({0,s});

    bool isAns=false;
    while(!q.empty()){
        int u = q.top().second , w = q.top().first; q.pop();

        if(u==t){
            if(isAns)return w;
            isAns = !isAns;
            continue;
        }

        for(auto x : adj[u]){
            int v=x.first , ww=x.second;
            q.push({ww+w , v});
        }
    }
    
    return 0x3f3f3f3f;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int v,e,s,t; cin >> v >> e >> s >> t;
    vector<pair<int,int>> adj[v+1];
    for(int i=0 ; i<e ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << solve(v,adj,s,t);

    return 0;
}
/*
3 3
1 3
1 2 1
1 2 2
2 3 1
*/