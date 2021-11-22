#include <bits/stdc++.h>

using namespace std;

bool ans=false;

void solve(int idx, int n, int sum, int arr[]){
    if(sum==0)ans=true;
    if(idx==n || ans)return;

    solve(idx+1,n,sum-arr[idx],arr);
    solve(idx+1,n,sum,arr);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {3, 34, 4, 12, 5, 2};
    int target = 30 , n = sizeof(arr)/sizeof(arr[0]);

    solve(0,n,target,arr);

    ans ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
