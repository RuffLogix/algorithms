#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int solve(int x){
    if(dp[x])return dp[x];
    if(x<=0)return 0x3f3f3f3f;
    if(x==1)return 0;
    
    int ans=solve(x-1)+1;
    if(x%2==0)ans = min(ans , solve(x/2)+1);
    if(x%3==0)ans = min(ans , solve(x/3)+1);
    
    return dp[x] = ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;

    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        cout << solve(x) << "\n";
    }

    return 0;
}