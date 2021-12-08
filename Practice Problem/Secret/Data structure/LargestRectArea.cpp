#include <bits/stdc++.h>

using namespace std;

int solve(int n,int arr[]){
    int ans=0;

    stack<int> s;
    int i=0;
    while(i<n){
        if(s.empty() || arr[s.top()] <= arr[i])s.push(i++);
        else{
            int top = s.top(); s.pop();

            int area = arr[top] * (s.empty() ? i : i-s.top()-1);

            ans = max(ans , area);
        }
    }

    while(!s.empty()){
        int top = s.top(); s.pop();

        int area = arr[top] * (s.empty() ? i : i-s.top()-1);

        ans = max(ans , area);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        int arr[n]; 
        for(int i=0 ; i<n ; i++)cin >> arr[i];

        cout << solve(n,arr) << "\n";
    }

    return 0;
}