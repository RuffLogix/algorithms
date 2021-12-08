/*
    Note : It doesn't work in real problem.

    1 1 1 
    1 2 2 = 20 -> correct answer 
    1 2 2

    1 2 2 
    1 2 2 = 24 -> incorrect answer
    1 1 1 
*/

#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int m,n; cin >> m >> n;
    int ans=0;
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> arr[i][j];
            if(arr[i][j]!=arr[i-1][j] && arr[i][j]!=arr[i][j-1] && arr[i][j]!=arr[i-1][j-1])
                dp[i][j] = 1;
            else if(arr[i][j]==arr[i-1][j] &&arr[i][j]!=arr[i][j-1]){
                dp[i][j] = dp[i-1][j] + 1;{}
            }else if(arr[i][j]==arr[i][j-1] &&arr[i][j]!=arr[i-1][j]){
                dp[i][j] = dp[i][j-1] + 1;
            }else if(arr[i][j]==arr[i-1][j-1] && arr[i][j]==arr[i-1][j] && arr[i][j]==arr[i-1][j]){
                dp[i][j] = dp[i][j-1] * dp[i-1][j] / dp[i-1][j-1];
            }

            ans += dp[i][j];
        }
    }

    cout << ans;

    return 0;
}