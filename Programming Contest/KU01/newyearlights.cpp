#include <bits/stdc++.h>

using namespace std;

vector<int> query[100001];
vector<pair<int,int>> adj[100001];
bool visited[100001];

void solve(){
    int ans=1;

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto x : adj[u]){
            if(visited[x.first] || query[x.first][x.second]==0)continue;
            if(--query[x.first][x.second] == 0 && !visited[x.first]){ans++;visited[x.first]=true;}
            q.push(x.first);
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int v,q; cin >> v >> q;

    for(int i=0 ; i<q ; i++){
        int k; cin >> k;
        int arr[k];
        for(int j=0 ; j<k ; j++){
            cin >> arr[j];
        }
        int t; cin >> t;
        for(int j=0 ; j<k ; j++){
            adj[arr[j]].push_back({t , query[t].size()});
        }
        query[t].push_back(k);
    }

    solve();

    return 0;
}