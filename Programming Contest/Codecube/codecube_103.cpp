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

    int n,p ; cin >> n >> p;

    vector<event> v;
    for(int i=0 ; i<n ; i++){
        int a,b; cin >> a >> b;
        if(a>b)swap(a,b);
        v.push_back({a,1});
        v.push_back({b,2});
    }

    sort(v.begin() , v.end());

    int cnt=0 , ans=0x3f3f3f3f;
    int s=-1,f=-1;
    for(auto e : v){
        if(e.type==1){
            if(++cnt==n)s=e.ti;
        }else{
            if(cnt--==n && s!=-1)f=e.ti;
        }
        if(s!=-1 && f!=-1){
            if(p>=s && p<=f)ans=0;
            else ans = min(abs(p-s) , abs(p-f));
        }
    }

    if(ans==0x3f3f3f3f){
        cout << "-1";
    }else if(s!=-1 && f!=-1){
        if(p>=s && p<=f)cout << 0;
        else{
            ans = min(abs(p-s) , abs(p-f));
            cout << ans;
        }
    }

    return 0;
}