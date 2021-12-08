#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> nn;
unordered_map<int,int> mm;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int l,w,n,m,q; cin >> l >> w >> n >> m >> q;

    int pre=0;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        nn[x-pre]++;
        pre = x;
    }
    nn[l-pre]++;
    pre=0;
    for(int i=0 ; i<m ; i++){
        int x; cin >> x;
        mm[x-pre]++;
        pre = x;
    }
    mm[w-pre]++;

    while(q--){
        int x;cin >> x;
        int ans=0;
        for(int i=1 ; i*i<=x ; i++){
            if(x%i==0)ans+=nn[i]*mm[x/i];
            if(x%i==0 && i*i!=x)ans+=nn[x/i]*mm[i];
        }
        cout << ans << "\n";
    }
    return 0;
}