#include <bits/stdc++.h>

using namespace std;

void solve(int idx,int n,int arr[]){

    for(int i=0 ; i<idx-1 ; i++){
        if(abs(idx-1-i)==abs(arr[idx-1]-arr[i]))return;
    }

    if(idx==n){
        for(int i=0 ; i<n ; i++)cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=idx ; i<n ; i++){
        swap(arr[i] , arr[idx]);
        solve(idx+1 , n , arr);
        swap(arr[i] , arr[idx]);
    }

}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n=10;
    int arr[n];

    for(int i=0 ; i<n ; i++) arr[i] = i+1;

    solve(0,n,arr);

    return 0;
}
