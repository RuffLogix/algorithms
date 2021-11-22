#include <bits/stdc++.h>

using namespace std;

bool visited[1001];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    pair<int,int> arr[] = {{2,100} , {2,27} , {1,25} , {1,15} , {1,19}};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr , arr+n , [&](pair<int,int> a,pair<int,int> b){
            return a.second > b.second;
         });

    int ans=0;
    for(int i=0 ; i<n ; i++){
        int t=arr[i].first;
        while(t>=1 && visited[t])t--;
        if(t>=1){
            visited[t] = true;
            ans+=arr[i].second;
        }
    }

    cout << ans;

    return 0;
}
