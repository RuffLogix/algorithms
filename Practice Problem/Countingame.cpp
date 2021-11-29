#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int solve(int n){
    //cout << n << "\n";
    if(dp[n])return dp[n];
    if(n==1)return 0;
    if(n<1)return 0x3f3f3f3f;
    int ans=0x3f3f3f3f;

    int new_n = n;
    int a=n%10;n=n/10;
    int b=n%10;n=n/10;
    int c=n%10;

    //cout << a << " " << b << " " << c << "\n";
    if(a!=5 && b!=5 && c!=5 && new_n%5!=0)ans = min(ans,solve(new_n-5)+1);
    if(a!=4 && b!=4 && c!=4 && new_n%4!=0)ans = min(ans,solve(new_n-4)+1);
    if(a!=3 && b!=3 && c!=3 && new_n%3!=0)ans = min(ans,solve(new_n-3)+1);
    if(a!=2 && b!=2 && c!=2 && new_n%2!=0)ans = min(ans,solve(new_n-2)+1);

    return dp[new_n] = ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n; cin >> n;

    int ans = solve(n);
    if(ans!=0x3f3f3f3f)cout << ans;
    else cout << -1;

    return 0;
}
