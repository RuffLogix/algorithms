#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int x=10;
    int arr[] = {1,2,5,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans=0;
    for(int i=n-1 ; i>=0 ; i--){
        if(x%arr[i]==0){
            ans+=x/arr[i];
            x%=arr[i];
        }
    }

    cout << ans;

    return 0;
}
