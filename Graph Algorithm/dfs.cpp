#include<bits/stdc++.h>

using namespace std;

void solve(int V,int S,vector<int> adj[]){
    vector<bool> visited(V+1,false);

    stack<int> s;

    s.push(S);
    visited[S] = true;
    while(!s.empty()){
        int u = s.top(); s.pop();
        cout << u << " ";
        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                s.push(v);
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
1 7
1 8
2 3
2 6
3 4
3 5
8 9
8 12
9 10
9 11
*/
