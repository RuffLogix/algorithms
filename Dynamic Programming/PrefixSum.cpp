#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);

    int dp[n+1];
    dp[0] = 0;
    for(int i=1 ; i<=n ; i++){
        dp[i] = dp[i-1]+arr[i-1];
        cout << dp[i] << " ";
    }

    return 0;
}
