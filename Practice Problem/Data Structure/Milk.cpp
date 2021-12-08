#include <bits/stdc++.h>

using namespace std;

int parent[1000001];

int f(int k){
    if(parent[k]==k)return k;
    return parent[k] = f(parent[k]);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n,m ; cin >> n >> m;

    for(int i=1 ; i<=n ; i++)parent[i] = i;

    for(int i=0 ; i<m ; i++){
        char cmd; cin >> cmd;
        int a,b; cin >> a >> b;

        if(cmd=='q'){
            if(f(a)==f(b))cout << "yes\n";
            else cout << "no\n";
        }else{
            parent[a] = b;
        }
    }
    return 0;
}