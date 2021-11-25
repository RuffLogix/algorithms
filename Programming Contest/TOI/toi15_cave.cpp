#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

int N,P,U,E;
vector<pair<int,int>> adj[2001];
int dist[2001][2001];
bitset<2001> visited[2001];
vector<pii> ans;

priority_queue<pair<int,pii> , vector<pair<int,pii>> , greater<pair<int,pii>>> q;

void solve(){
    memset(dist , 0x3f3f3f3f , sizeof(dist));

    int mxt=0x3f3f3f3f , mxw=0x3f3f3f3f;
    while(!q.empty()){
        int u = q.top().second.first , n = q.top().second.second , ww = q.top().first; q.pop();

        if(n>mxt && mxw<ww)continue;
        if(dist[u][n] <= ww && u!=U)continue;
        visited[u][n] = true;

        dist[u][n] = ww;

        if(u==U){
            mxt = min(mxt , n);
            mxw = min(mxw , ww);

            ans.push_back({n,ww});
            continue;
        }

        for(auto [v,w] : adj[u]){
            if(!visited[v][n+1])q.push({w+ww , {v,n+1}});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> N >> P >> U >> E;

    for(int i=0 ; i<E ; i++){
        int Q,R,T; cin >> Q >> R >> T;
        adj[Q].push_back({R,T});
        if(Q==P)q.push({T,{R,0}});
    }

    int L; cin >> L;

    solve();

    for(int i=0 ; i<L ; i++){
        int h; cin >> h;
        int anss=0x3f3f3f3f;
        for(auto x : ans){
            anss = min(anss , x.first*h+x.second);
        }
        cout << anss << " ";
    }

    return 0;
}
