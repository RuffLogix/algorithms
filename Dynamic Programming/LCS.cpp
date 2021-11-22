#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    string s1 = "0K4I4J2A3P0U0K00";
    string s2 = "KITJAPUK044230000";

    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])dp[i][j] = dp[i-1][j-1] + 1;
            else {
                dp[i][j] = max(dp[i-1][j-1] , max(dp[i-1][j] , dp[i][j-1]));
            }
        }
    }

    cout << dp[n][m];

    return 0;
}
