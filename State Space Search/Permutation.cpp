#include <bits/stdc++.h>

using namespace std;

solve(int idx,int n,int arr[]){
    if(idx==n){
        for(int i=0 ; i<n ; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for(int i=idx ; i<n ; i++){
        swap(arr[idx] , arr[i]);
        solve(idx+1,n,arr);
        swap(arr[idx] , arr[i]);
    }
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n=4;
    int arr[n];

    for(int i=0 ; i<n ; i++)arr[i] = i+1;

    solve(0,n,arr);

    return 0;
}
