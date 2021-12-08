#include <bits/stdc++.h>

using namespace std;

stack<pair<int,int>> st;
int dp[100001];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n,k; cin >> n >> k;

    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        while(!st.empty() && st.top().second>=x)st.pop();
        if(!st.empty())dp[i] = max(dp[st.top().first] , x-st.top().second);
        st.push({i,x});
    }

    sort(dp,dp+n);

    for(int i=0 ; i<k ; i++){
        int x; cin >> x;
        cout << n-(upper_bound(dp , dp+n , x)-dp) << "\n";
    }

    return 0;
}