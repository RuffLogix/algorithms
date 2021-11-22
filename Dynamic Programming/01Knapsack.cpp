#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int v[] = {60 , 100 , 120};
    int w[] = {10 , 20 , 30};
    int W = 50 , n = sizeof(w)/sizeof(w[0]);

    int dp[W+1];
    memset(dp , 0 , sizeof(dp));
    for(int i=0 ; i<n ; i++){

        for(int j=W-w[i] ; j>=0 ; j--){
            if(dp[j] || j==0){
                dp[j+w[i]] = max(dp[j+w[i]] , dp[j]+v[i]);
            }
        }

    }

    cout << dp[W];

    return 0;
}
