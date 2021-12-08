#include <bits/stdc++.h>

using namespace std;

int ans , sum;
int value[100001];
bool visited[100001];

int solve(int u,int p,vector<int> adj[]){
    visited[u] = true;
    int child = value[u-1];
    for(auto v : adj[u]){
        if(!visited[v]){
            int tmp = solve(v , u, adj);
            child += tmp;
            ans = min(ans , abs(sum - 2*(tmp+value[u-1])));    
        }
    }

    return child;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int t; cin >> t;

    while(t--){
        memset(visited , false , sizeof(visited));
        ans = 0x3f3f3f3f , sum = 0;

        int n; cin >> n;

        vector<int> adj[n+1];
        for(int i=0 ; i<n-1 ; i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0 ; i<n ; i++){
            cin >> value[i];
            sum += value[i];
        }
        
        solve(1,-1,adj);

        cout << ans << "\n";
    }

    return 0;
}