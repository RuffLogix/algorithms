#include <bits/stdc++.h>

using namespace std;

struct event{
    int ti,type;
    bool operator < (const event&e) const {
        if(ti==e.ti)return type<e.type;
        return ti<e.ti;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;

    vector<event> Event;
    for(int i=0 ; i<n ; i++){
        int a,b; cin >> a >> b;
        Event.push_back({b,1});
        Event.push_back({a,2});
    }

    sort(Event.begin() , Event.end());

    int cnt=0 , ans=0;
    for(auto e : Event){
        (e.type==1) ? cnt-- : cnt++;
        ans = max(ans , cnt);
    }

    cout << ans;

    return 0;
}