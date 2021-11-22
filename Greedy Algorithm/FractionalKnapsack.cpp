#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    pair<float,float> arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr , arr+n , [&](pair<int,int> a,pair<int,int> b){
            return a.first/a.second > b.first/b.second;
         });

    float ans=0;
    for(int i=0 ; i<n ; i++){
        if(W>=arr[i].second){
            W-=arr[i].second;
            ans+=arr[i].first;
        }else if(W>0){
            ans+=arr[i].first/arr[i].second*W;
            W=0;
        }
    }
    cout << ans;
    return 0;
}
