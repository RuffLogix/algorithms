#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

vector<pii> adj[1001];
priority_queue<pair<int , pii> , vector<pair<int , pii>> , greater<pair<int , pii>>> q;
vector<int> dist(1001 , 0x3f3f3f3f);

void solve(){

    while(!q.empty()){
        int u = q.top().second.first , uu = q.top().second.second , ww = q.top().first; q.pop();

        if(u=='Z'){
            cout << (char)uu << " " << ww;
            return;
        }

        for(auto x : adj[u]){
            int v = x.first , w = x.second;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u] + w;
                q.push({w+ww , {v , uu}});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;

    for(int i=0 ; i<n ; i++){
        char u,v;
        int w; 
        cin >> u >> v >> w;
        if(u>='A' && u<='Z'){q.push({0,{(int)u,(int)u}});dist[(int)u] = 0;}
        adj[(int)u].push_back({(int)v,w});
    }

    solve();
    return 0;
}
/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/