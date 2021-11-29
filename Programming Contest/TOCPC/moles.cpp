/*
    score : 60/100
    related topic : dynamic programming
*/

#include <bits/stdc++.h>

using namespace std;

struct mole{
    int s,t;
    bool operator<(const mole&m){
        return t<m.t;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n,s; cin >> n >> s;

    mole arr[n+1];
    arr[0] = {s,0};
    for(int i=1 ; i<=n ; i++)cin >> arr[i].s >> arr[i].t;

    sort(arr , arr+n+1);

    int dp[n+1];
    for(int i=0 ; i<=n ; i++){
        dp[i] = 0;
        for(int j=0 ; j<i ; j++){
            if(abs(arr[j].s-arr[i].s) <= arr[i].t-arr[j].t){
                dp[i] = max(dp[i] , dp[j]+1);
            }
        }
        //cout << dp[i] << " ";
    }

    cout << dp[n];

    return 0;
}
