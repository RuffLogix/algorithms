#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int notes[301];

int solve(int l,int r,int k){
    int ans = 0x3f3f3f3f;

    for(int i=l+1 ; i<r ; i++){
        ans = min(ans , solve(l,i,k) + solve(i+1,r,k) + arr[notes[l]][notes[i]] + arr[notes[l+1]][notes[r]]);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n,m,k; cin >> n >> m >> k;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0 ; i<m ; i++){
        cin >> notes[i];
    }

    cout << solve(0,m-1,k);
    return 0;
}