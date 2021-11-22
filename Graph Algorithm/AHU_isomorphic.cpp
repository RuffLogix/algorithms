#include <bits/stdc++.h>

using namespace std;

int getCenter(vector<int> tree[],int V){
    int ans = (V*(V-1))/2;
    int remained_tree=V;
    vector<int> cnt(V,0);

    while(remained_tree>=2){
        vector<int> tmp(V,0);
        for(int i=0 ; i<V ; i++){
            if(tree[i].size()-cnt[i]==1){
                tmp[i]++;
                remained_tree--;
                ans-=i;
                for(auto v : tree[i]){
                    tmp[v]++;
                }
            }
        }

        for(int i=0 ; i<V ; i++){
            cnt[i] += tmp[i];
        }
    }

    return ans;
}

string encode(vector<int> tree[],int u,int p){
    string ans = "";
    if(tree[u].size()==1)return "()";

    for(auto v : tree[u]){
        if(v!=p) ans += encode(tree,v,u);
    }

    ans = "(" + ans + ")";

    return ans;
}

bool AHU(vector<int> tree1[] ,vector<int> tree2[] ,int V){
    bool ans;

    int center1 = getCenter(tree1,V);
    int center2 = getCenter(tree2,V);

    string s1 = encode(tree1 , center1 , -1);
    string s2 = encode(tree2 , center2 , -1);

    s1 == s2 ? ans=true : ans=false;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V=7,E=6;
    vector<int> tree1[V];
    vector<int> tree2[V];

    for(int i=0 ; i<E ; i++){
        int u,v; cin >> u >> v;
        tree1[u].push_back(v);
        tree1[v].push_back(u);
    }

    for(int i=0 ; i<E ; i++){
        int u,v; cin >> u >> v;
        tree2[u].push_back(v);
        tree2[v].push_back(u);
    }

    if(AHU(tree1 , tree2 , V)){
        cout << "tree1 and tree2 are isomorphic graph\n";
    }else{
        cout << "tree1 and tree2 are not isomorphic graph\n";
    }

    return 0;
}

/*
0 1
0 2
2 6
2 5
2 3
3 4

1 2
2 3
3 4
3 0
3 5
5 6
*/
