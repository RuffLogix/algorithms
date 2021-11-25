#include <bits/stdc++.h>
#define edge vector<pair<int,pair<int,int>>>
using namespace std;

edge adj;

void AddEdge(int a,int b,int w){
    adj.push_back({w,{a,b}});
}

int f(vector<int> parent , int k){
    if(parent[k]==k || parent[k]==-1)return k;
    return parent[k] = f(parent , parent[k]);
}

void solve(int V,int E){
    vector<int> parent(V,-1);

    sort(adj.begin() , adj.end());

    int i=0;
    int ans=0;
    for(auto e : adj){
        if(i==V)break;
        int a = f(parent,e.second.first);
        int b = f(parent,e.second.second);

        if(a!=b){
            parent[a] = b;
            ans += e.first;
            i++;
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V = 9;
    int E = 14;

    AddEdge(0,1,4);
    AddEdge(0,7,8);
    AddEdge(1,7,11);
    AddEdge(1,2,8);
    AddEdge(7,8,7);
    AddEdge(7,6,1);
    AddEdge(8,6,6);
    AddEdge(2,8,2);
    AddEdge(2,3,7);
    AddEdge(2,5,4);
    AddEdge(6,5,2);
    AddEdge(3,5,14);
    AddEdge(3,4,9);
    AddEdge(5,4,10);

    solve(V,E);

    return 0;
}
