#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n,a,b; cin >> n >> a >> b;

    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    int ans=0;
    int mn=0x3f3f3f3f;
    for(int i=b ; i>=a ; i--){
        int cnt=0;
        int sum=0;
        for(int j=0 ; j<n ; j++){
            if(arr[j]>i){
                cnt=0x3f3f3f3f;
                break;
            }
            if(sum+arr[j] > i){
                cnt+=i-sum;
                sum=arr[j];
            }else{
                sum+=arr[j];
            }
        }
        if(cnt <= mn){
            ans=i;
            mn = cnt;
        }
    }

    cout << ans;
    return 0;
}
