#include <bits/stdc++.h>

using namespace std;

int solve(int l,int r,int arr[]){
    if(l==r)return 0;

    int mn = 0x3f3f3f3f;
    for(int i=l ; i<r ; i++){
        mn = min(mn , solve(l,i,arr) + solve(i+1,r,arr) + arr[l-1]*arr[i]*arr[r]);
    }

    return mn;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << solve(1,n-1,arr);

    return 0;
}
