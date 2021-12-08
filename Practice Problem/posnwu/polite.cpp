#include <bits/stdc++.h>

using namespace std;

bitset<500001> ispolite;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    ispolite.flip();

    for(int i=0 ; 2<<i <=500000 ; i++){
        ispolite[2<<i] = false;
    }

    int n; cin >> n;

    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        int ans=0;
        for(int i=3 ; i<=x/2 ; i++){
            if(ispolite[x-i] && ispolite[i])ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}