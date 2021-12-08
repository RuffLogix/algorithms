//;-;
#include <bits/stdc++.h>

using namespace std;

vector<pair<long long int,long long int>> adj[80001];
bool speedup_potion[80001];
bool visited[80001][10];
long long int dist[80001][10];
long long int n,m,l,q;

void solve(){
    memset(dist , 0x3f3f3f3f , sizeof(dist));
    priority_queue<pair<pair<long long int,long long int>,pair<long long int,long long int>> , vector<pair<pair<long long int,long long int>,pair<long long int,long long int>>> , greater<pair<pair<long long int,long long int>,pair<long long int,long long int>>>> pq;// time , v , potion , parent

    if(speedup_potion[1] && q>=1)pq.push({{0,1},{1,1}});
    pq.push({{0,1},{0,-1}});

    while(!pq.empty()){
        auto tmp = pq.top() ; pq.pop();
        if(visited[tmp.first.second][tmp.second.first])continue;
        if(dist[tmp.first.second][tmp.second.first] <= tmp.first.first)continue;
        if(tmp.second.first > q)continue;
        visited[tmp.first.second][tmp.second.first] = true;
        dist[tmp.first.second][tmp.second.first] = tmp.first.first;
        if(tmp.first.second==n){
            cout << tmp.first.first << "\n";
            return;
        }
        for(auto n_a : adj[tmp.first.second]){
            if(!visited[n_a.first][tmp.second.first]){
                pq.push({{tmp.first.first+(n_a.second>>tmp.second.first) , n_a.first }, {tmp.second.first , -1}});
            }
            if(!visited[n_a.first][tmp.second.first+1] && speedup_potion[n_a.first] && n_a.first!=tmp.second.second){
                pq.push({{tmp.first.first+(n_a.second>>(tmp.second.first)) , n_a.first },{ tmp.second.first+1 , tmp.first.second}});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> m >> l >> q;

    for(int i=0 ; i<m ; i++){
        long long int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    for(int i=0 ; i<l ; i++){
        int x; cin >> x;
        speedup_potion[x] = true;
    }
    
    solve();

    return 0;
}