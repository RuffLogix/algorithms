#include <bits/stdc++.h>

using namespace std;

int n,m,s,d,p; 

struct edge{
    int u,v,w;
    bool operator<(const edge&ee){
        return w>ee.w;
    }
};

int f(int *p, int k){
    if(p[k]==k || p[k]==-1)return k;
    return p[k] = f(p , p[k]);
}

int solve(vector<edge> e){
    int parent[n+1];
    memset(parent , -1 , sizeof(parent));

    int i=0;
    for(auto u : e){
        if(i>=n)break;
        int a = f(parent , u.u);
        int b = f(parent , u.v);

        if(a!=b){
            parent[a] = b;
            //cout << u.v << " " << u.u << " " << u.w << "\n";
            //cout << f(parent,s) << " " << f(parent,d) << "\n";
            if(f(parent,s) == f(parent,d)){
                return ceil(double(p)/double(u.w-1)) ;
            }
            i++;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> m;
    vector<edge> e;
    for(int i=0 ; i<m ; i++){
        int u,v,w; cin >> u >> v >> w;
        e.push_back({u,v,w});
    }

    sort(e.begin() , e.end());

    cin >> s >> d >> p;

    cout << solve(e);

    return 0;
}
