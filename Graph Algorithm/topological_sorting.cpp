#include <bits/stdc++.h>

using namespace std;

stack<int> s;

void topo(int V , vector<int> adj[] , bool visited[]){
    visited[V] = true;

    for(auto v : adj[V]){
        if(!visited[v]){
            topo(v , adj , visited);
        }
    }

    s.push(V);
}

void solve(int V , int E , vector<int> adj[]){
    bool visited[V];
    memset(visited , false , sizeof(visited));
    for(int i=0 ; i<V ; i++){
        if(!visited[i]){
            topo(i , adj , visited);
        }
    }

    while(!s.empty()){
        cout << s.top()+1 << " ";
        s.pop();
    }
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; cin >> V >> E;
    vector<int> adj[V];
    for(int i=0 ; i<E ; i++){
        int u,v; cin >> u >> v;
        adj[u-1].push_back(v-1);
    }

    solve(V,E,adj);


    return 0;
}

/*
8 9
1 4
1 5
2 4
3 5
3 8
4 6
4 7
4 8
5 7
*/
