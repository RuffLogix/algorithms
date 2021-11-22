#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {1,2,3,4,5,6,7,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int dp[n];
    int ans=0;
    for(int i=0 ; i<n ; i++){
        dp[i] = 1;
        for(int j=0 ; j<i ; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i] , dp[j]+1);
            }
        }
        ans = max(ans , dp[i]);
    }

    cout << ans;

    return 0;
}
