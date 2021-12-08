#include <bits/stdc++.h>

#define N 10001
#define pii pair<int,int>

using namespace std;

int dp[N];

int main() {
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n, m; cin >> n >> m;

    stack <pii> s;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;

        while(!s.empty() && s.top().first >= x) s.pop();
        if(!s.empty()) dp[i] = max(dp[s.top().second], x-s.top().first);
        s.emplace(x, i);
    }

    sort(dp+1, dp+n+1);

    while(m--) {
        int k; cin >> k;
        cout << n-(upper_bound(dp+1 , dp+n+1 , k)-dp-1) << "\n";
    }

    return 0;
}