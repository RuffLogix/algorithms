#include <bits/stdc++.h>

using namespace std;

struct work{
    int s,t,w;
    bool operator < (const work&ww){
        if(t==ww.t)return w<ww.w;
        return t<ww.t;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;

    work arr[n];
    for(int i=0 ; i<n ; i++){
        int a,b,c ; cin >> a >> b >> c;
        arr[i] = {a,b,c};
    }

    sort(arr , arr+n);

    int dp[n];
    int ans=0;
    for(int i=0 ; i<n ; i++){
        dp[i] = arr[i].w;
        int st=arr[i].s;
        for(int j=0 ; j<i ; j++){
            if(arr[j].t<=st){
                dp[i]+=dp[j];
            }
        }

        ans = max(ans , dp[i]);
    }

    cout << ans;

    return 0;
}
/*
3
1 3 2
2 4 10
3 5 2
*/