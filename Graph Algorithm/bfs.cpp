#include<bits/stdc++.h>

using namespace std;

void solve(int V,int S,vector<int> adj[]){
    vector<bool> visited(V+1,false);

    queue<int> q;

    q.push(S);
    visited[S] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << " ";
        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E,S; cin >> V >> E >> S;

    vector<int> adj[V+1];
    for(int i=0 ; i<E ; i++){
        int u,v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(V,S,adj);

    return 0;
}
/*
12 11 1
1 2
1 3
1 4
2 5
2 6
4 7
4 8
5 9
5 10
7 11
7 12
*/
