#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n,m; cin >> n >> m;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    for(int i=0 ; i<n+m ; i++){
        char cmd; cin >> cmd;
        if(cmd=='T'){
            int w,v; cin >> w >> v;
            pq.emplace(w,v);
        }else{
            if(pq.empty()){
                cout << "0";
            }else{
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}
/*
3 4
T 10 20
T 5 10
P 
T 7 30
P
P
P
*/