#include <bits/stdc++.h>

using namespace std;

struct gem{
    int value,ti,idx;
    bool operator < (const gem&g)const{
        if(value==g.value)return ti>g.ti;
        return value < g.value;
    }
};

int current_time = 0;
priority_queue<gem> qq;
bool visited[100001];

int ans=0;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int t; cin >> t;

    for(int i=0 ; i<t ; i++){
        char c; cin >> c;
        while(!qq.empty() && (qq.top().ti < current_time || visited[qq.top().idx]))qq.pop();
        if(c=='c'){
            char ty; cin >> ty;
            if(ty=='n'){
                int v; cin >> v;
                qq.push({v,0x3f3f3f3f,i});
            }else{
                int v,d; cin >> v >> d;
                qq.push({v,current_time+d-1,i});
                v = v>>1; d+=d;
                while(v!=0){
                    qq.push({v,current_time+d-1,i});
                    v = v>>1;
                    d+=d;
                }
            }
        }else if(c=='u'){
            while(qq.top().ti < current_time || visited[qq.top().idx])qq.pop();
            if(!visited[qq.top().idx]){
                visited[qq.top().idx] = true;
                ans+=qq.top().value; qq.pop();
            }
        }
        current_time++;
    }

    int nub=0;
    while(!qq.empty()){
        if(!visited[qq.top().idx]){
            visited[qq.top().idx] = true;
            nub++;
        }
        qq.pop();
    }

    cout << ans << "\n" << nub;

    return 0;
}
