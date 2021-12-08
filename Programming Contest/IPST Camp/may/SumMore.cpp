#include <bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n,k; cin >> n >> k;
    int arr[n+1];
    arr[0] = 0;
    for(int i=1 ; i<=n ; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int ans=0;
    for(int i=1 ; i<=n ; i++){
        for(int j=i ; j<=n ; j++){
            if(arr[j]-arr[i-1]>=k)ans++;
        }
    }
    cout << ans;

    return 0;
}