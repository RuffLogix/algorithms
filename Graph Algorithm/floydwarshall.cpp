#include <bits/stdc++.h>

using namespace std;

int adj[10][10];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; cin >> V >> E;

    memset(adj , 0x3f3f3f3f , sizeof(adj));
    for(int i=0 ; i<E ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for(int k=1 ; k<=V ; k++){
        for(int i=1 ; i<=V ; i++){
            for(int j=1 ; j<=V ; j++){
                if(i==j) adj[i][j] = 0;
                else if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for(int i=1 ; i<=V ; i++){
        for(int j=1 ; j<=V ; j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
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
*/
