#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    long long T; cin >> T;

    while(T--){
        long long n; cin >> n;
        long long arr[n]; 
        for(long long i=0 ; i<n ; i++) cin >> arr[i];

        long long i=0; stack<long long> s;
        long long ans = 0;
        while(i<n){
            if(s.empty() || arr[s.top()]<=arr[i])s.push(i++);
            else {
                long long t=s.top(); s.pop();
                long long area = arr[t] * (s.empty() ? i : i-s.top()-1);
                ans = max(ans , area);
            }
        }

        while(!s.empty()){
            long long t=s.top(); s.pop();
            long long area = arr[t] * (s.empty() ? i : i-s.top()-1);
            ans = max(ans , area);
        }
        cout << ans << "\n";
    }

    return 0;
}