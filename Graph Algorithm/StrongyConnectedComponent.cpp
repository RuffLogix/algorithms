#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(1001,false);
int disc[1001] , low[1001];
vector<int> S;
vector<int> adj[1001];

int cnt=0;

void tarjanSCC(int u){
    disc[u] = low[u] = cnt++;
    visited[u] = true;
    S.push_back(u);
    for(auto v : adj[u]){
        if(!visited[v]){
            tarjanSCC(v);
        }
        if(visited[v]){
            low[u] = min(low[u] , low[v]);
        }
    }

    if(disc[u] == low[u]){
        cout << "SCC : ";
        while(true){
            int v = S.back() ; S.pop_back();
            cout << v << " ";
            if(u==v)break;
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; cin >> V >> E;

    for(int i=0 ; i<E ; i++){
        int u,v ; cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i=0 ; i<V ; i++){
        if(!visited[i]){
            tarjanSCC(i);
        }
    }

    return 0;
}
/*
8 9
0 1
2 1
1 3
3 2
3 4
4 5
5 7
7 6
6 4
*/
