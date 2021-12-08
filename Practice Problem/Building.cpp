#include <bits/stdc++.h>

using namespace std;

int n,m,nub; 

void solve(int l,int r,int arr[]){
    if(l==r)return;

    int m = (l+r)>>1;

    /*I am so sleepy so in the morning I will do this again. goodnight have a nice dream.*/
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int t; cin >> t;

    while(t--){
        nub = 0;
        cin >> n >> m;
        int arr[n+1];
        arr[0] = 0;
        for(int i=1 ; i<=n ; i++)cin >> arr[i];

        solve(1,n,arr);

        cout << nub;
    }

    return 0;
}