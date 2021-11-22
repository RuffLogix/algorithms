#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {30,50,40,20,60};
    int n = sizeof(arr)/sizeof(arr[0]);

    int dp[n+1];
    dp[0] = 1;
    dp[1] = arr[0];
    for(int i=2 ; i<=n ; i++){
        dp[i] = max(dp[i-2]+arr[i-1] , dp[i-1]);
    }

    cout << dp[n];

    return 0;
}
