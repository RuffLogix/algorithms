#include <bits/stdc++.h>

using namespace std;

int p[100001];

int f(int k){
    if(p[k]==0 || p[k]==k)return p[k] = k;
    return p[k] = f(p[k]);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n,m; cin >> n >> m;

    for(int i=0 ; i<m ; i++){
        int u,v; cin >> u >> v;
        p[f(u)] = f(v);
    }

    int q; cin >> q;

    while(q--){
        int u,v; cin >> u >> v;
        if(f(u)==f(v)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}
/*
5 4 
3 5 
3 4 
2 5
3 2 
3 
1 5 
2 4 
2 1
*/