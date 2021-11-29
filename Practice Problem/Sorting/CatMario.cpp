#include <bits/stdc++.h>

using namespace std;

struct video{
    int level,mins;

    bool operator < (const video&v){
        if(level==v.level)return mins < v.mins;
        return level<v.level;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n,m ; cin >> n >> m;

    vector<video> v;
    for(int i=0 ; i<m ; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    vector<video> ans;
    int v_ans=0;
    int curr=1;
    for(auto x : v){
        if(curr==x.level){
            v_ans+=x.mins;
            ans.push_back(x);
            curr++;
        }
    }

    cout << v_ans << "\n";
    for(auto x : ans){
        cout << x.level << " " << x.mins << "\n";
    }

    return 0;
}
/*
3 4
1 55
2 20
1 28
3 50
*/
