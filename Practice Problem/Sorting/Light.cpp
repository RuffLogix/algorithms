#include <bits/stdc++.h>

using namespace std;

struct Event{
    int time , type;
    bool operator < (const Event&ee){
        if(time==ee.time)return type<ee.type;
        return time<ee.time;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n,m; cin >> n >> m;

    vector<Event> e;
    for(int i=0 ; i<n ; i++){
        int a,b; cin >> a >> b;
        e.push_back({a,2});
        e.push_back({b,0});
    }

    for(int i=0 ; i<m ; i++){
        int x; cin >> x;
        e.push_back({x,1});
    }

    sort(e.begin() , e.end());

    int ans=0;
    int curr=0;
    for(auto event : e){
        //cout << event.time << " " << event.type << "\n";
        if(event.type==0)curr--;
        else if(event.type==2)curr++;
        else if(event.type==1)ans+=curr;
    }
    cout << ans;

    return 0;
}
/*
4 5
10 30
5 15
1 15
5 50
5
12
15
40
80
*/
