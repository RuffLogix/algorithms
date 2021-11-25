#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

void AddEdge(vector<pair<int,int>> adj[],int a,int b,int w){
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
}

void solve(vector<pair<int,int>> adj[],int V,int E){
    vector<bool> visited(V,false);

    priority_queue<pii , vector<pii> , greater<pii>> q;

    q.push({0 , 0});

    int ans=0 , i=0;
    while(!q.empty() && i<V){
        int u = q.top().second;
        if(!visited[u]){
            i++;
            ans+=q.top().first;
        }
        q.pop();
        visited[u] = true;

        for(auto v : adj[u]){
            if(!visited[v.first]){
                q.push({v.second , v.first});
            }
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V = 9;
    int E = 14;
    vector<pair<int,int>> adj[V];

    AddEdge(adj,0,1,4);
    AddEdge(adj,0,7,8);
    AddEdge(adj,1,7,11);
    AddEdge(adj,1,2,8);
    AddEdge(adj,7,8,7);
    AddEdge(adj,7,6,1);
    AddEdge(adj,8,6,6);
    AddEdge(adj,2,8,2);
    AddEdge(adj,2,3,7);
    AddEdge(adj,2,5,4);
    AddEdge(adj,6,5,2);
    AddEdge(adj,3,5,14);
    AddEdge(adj,3,4,9);
    AddEdge(adj,5,4,10);

    solve(adj,V,E);

    return 0;
}
