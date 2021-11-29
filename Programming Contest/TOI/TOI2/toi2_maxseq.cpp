#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;
    int arr[n];
    int mx = 0;
    pair<int,int> ans = {0,0};
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        arr[i] = x;
        mx+x < x ? mx = x : mx += x;

        if(mx > ans.first)ans = {mx , i};
    }

    if(ans.first==0){
        cout << "Empty sequence";
        return 0;
    }

    int i=ans.second ; mx=ans.first;
    for( ; i>=0 ; i--){
        mx-=arr[i];
        if(mx==0)break;
    }

    for( ; i<=ans.second ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n" << ans.first;

    return 0;
}