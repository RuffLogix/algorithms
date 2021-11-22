#include <bits/stdc++.h>

using namespace std;

solve(int idx,int k,int n,int arr[],bool visited[]){
    if(idx==k){
        for(int i=0 ; i<k ; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int bb = idx==0 ? 0 : arr[idx-1];
    for(int i=bb ; i<n ; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[idx] = i+1;
            solve(idx+1 , k , n , arr , visited);
            visited[i] = false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n=4,k=2;
    int arr[n];

    bool visited[n];
    memset(visited , false , sizeof(visited));

    solve(0,k,n,arr,visited);

    return 0;
}
