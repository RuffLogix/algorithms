#include <bits/stdc++.h>

using namespace std;

int ans=0;

void solve(int l,int r,int arr[]){
    if(l==r)return;

    int m = (l+r)/2;

    solve(l,m,arr);
    solve(m+1,r,arr);

    int arrL[m-l+1];
    int arrR[r-m];

    for(int i=0 ; i<m-l+1 ; i++)arrL[i] = arr[i+l];
    for(int i=0 ; i<r-m ; i++)arrR[i] = arr[i+m+1];

    int i=0 , j=0 , idx=l;
    while(i<m-l+1 && j<r-m){
        if(arrL[i]<=arrR[j]){
            arr[idx++] = arrL[i++];
        }else{
            ans+=(m-l+1)-i;
            arr[idx++] = arrR[j++];
        }
    }

    while(i<m-l+1){
        arr[idx++] = arrL[i++];
    }

    while(j<r-m){
        arr[idx++] = arrR[j++];
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    solve(0,n-1,arr);

    cout << ans;
    return 0;
}
