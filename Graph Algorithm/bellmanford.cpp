#include <bits/stdc++.h>

using namespace std;

bool solve(int src,int des,int V,vector<pair<int,pair<int,int>>> edge){
    vector<bool> visited(V+1 , false);
    vector<int> dist(V+1 , 0x3f3f3f3f);

    dist[src] = 0;
    bool ischange = false , isNegCycle = false;
    int cnt=0;
    do{
        ischange=false;
        for(auto e : edge){
            if(dist[e.second.first] > dist[e.second.second] + e.first){
                dist[e.second.first] = dist[e.second.second] + e.first;
                ischange = true;
            }
        }
        cnt++;

        if(cnt>V && ischange){
            isNegCycle = true;
            break;
        }
    }while(ischange);

    //cout << dist[des]; // display distance from src to des.
    return isNegCycle;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; cin >> V >> E;

    vector<pair<int,pair<int,int>>> edge;

    for(int i=0 ; i<E ; i++){
        int u,v,w ; cin >> u >> v >> w;
        edge.push_back({w,{u,v}});
        edge.push_back({w,{v,u}});
    }

    int S,D; cin >> S >> D;
    if(solve(S,D,V,edge)){
        cout << "Wow I found negative weight cycle\n";
    }else{
        cout << "T_T I didn't found negative weight cycle\n";
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
1 4
*/
