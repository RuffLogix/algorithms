#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
int disc[1001] , low[1001];
bool visited[1001];

int counter=0;

void solve(int u,int p){
    visited[u] = true;
    low[u] = disc[u] = counter++;
    int child = 0;
    for(auto v : adj[u]){
        if(!visited[v]){
            child++;
            solve(v,u);

            low[u] = min(low[u] , low[v]);

            if((p==-1 && child>1) || (p!=-1 && low[v] >= disc[u]))
                cout << u << "\n";

            if(low[v] > disc[u])
                cout << u << "->" << v << "\n";
        }else if(v!=p){
            low[u] = min(low[u] , disc[v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    int V,E ; cin >> V >> E;

    for(int i ; i<E ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(2 , -1);

    return 0;
}
/*
5 5
1 0
1 2
0 2
0 3
3 4
*/
