#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int x = 5;
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int dp[x+1];
    memset(dp , 0x3f3f3f3f , sizeof(dp));
    dp[0] = 0;
    for(int i=0 ; i<=x ; i++){
        for(int j=0 ; j<n ; j++){
            if(i+arr[j]<=x){
                dp[i+arr[j]] = min(dp[i+arr[j]] , dp[i]+1);
            }
        }
    }

    cout << dp[x];

    return 0;
}
