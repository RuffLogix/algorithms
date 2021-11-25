#include <bits/stdc++.h>

using namespace std;

bool solve(int src,int des,int V,vector<pair<int,int>> adj[]){
    vector<bool> visited(V+1 , false);
    vector<int> dist(V+1 , 0x3f3f3f3f);
    vector<int> cnt(V+1 , 0);

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;

    dist[src] = 0;
    q.push({0,src});
    bool ischange = false , isNegCycle = false , iscnt = false;

    do{
        int u = q.top().second; q.pop();
        visited[u] = true;

        ischange=false;
        for(auto v : adj[u]){
            if(!visited[v.first] && dist[v.first] > dist[u] + v.second){
                if(cnt[v.first]++==V) iscnt = true;
                dist[v.first] = dist[u] + v.second;
                q.push({dist[v.first],v.first});
                ischange = true;
            }
        }

        if(iscnt && ischange){
            isNegCycle = true;
            break;
        }
    }while(ischange);

    //cout << dist[des]; display distance from src to des.
    return isNegCycle;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; cin >> V >> E;

    vector<pair<int,int>> adj[V+1];

    for(int i=0 ; i<E ; i++){
        int u,v,w ; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int S,D; cin >> S >> D;
    if(solve(S,D,V,adj)){
        cout << "Wow I found negative weight cycle\n";
    }else{
        cout << "T_T I didn't found negative weight cycle\n";
    }

    return 0;
}
/*
4 5
1 2 2
1 4 8
2 3 2
2 4 4
3 4 1
1 4
*/
