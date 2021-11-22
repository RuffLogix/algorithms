#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = 0;
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        if(sum + arr[i]  < arr[i]){
            sum = arr[i];
        }else{
            sum += arr[i];
        }
        ans = max(ans , sum);
    }

    cout << ans;

    return 0;
}
