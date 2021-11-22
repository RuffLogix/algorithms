#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[3][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    int n = sizeof(arr)/sizeof(arr[0]) , m = sizeof(arr[0])/sizeof(arr[0][0]);

    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(i==1 && j==1)dp[i][j] = 1;
            else if(arr[i-1][j-1]==0)dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[n][m];

    return 0;
}
