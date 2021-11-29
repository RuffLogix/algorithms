#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n; cin >> n;
    int X[n] , Y[n];

    for(int i=0 ; i<n ; i++)cin >> X[i];
    for(int i=0 ; i<n ; i++)cin >> Y[i];

    sort(X,X+n);
    sort(Y,Y+n,greater<int>());

    int ans=-0x3f3f3f3f;
    for(int i=0 ; i<n ; i++){
        ans = max(ans , min(X[i],Y[i]));
        //cout << X[i] << " " << Y[i] << "\n";
    }
    cout << ans;
    return 0;
}
/*
4
10
20
15
17
13
17
19
16
*/
