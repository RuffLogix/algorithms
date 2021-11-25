#include <bits/stdc++.h>

using namespace std;

int K[1001] , L[1001];
int M,N;

pair<int,int> dp[1001][1001];

pair<int,int> update(pair<int,int> a , int v){
    return {a.second+v<=M ? a.first : a.first+1 , a.second+v<=M ? a.second+v : v};
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> M >> N;

    for(int i=0 ; i<N ; i++)cin >> K[i];
    for(int i=0 ; i<N ; i++)cin >> L[i];

    for(int i=0 ; i<=N ; i++){
        for(int j=0 ; j<=N ; j++){
            //if(i==0 && j==0) dp[i][j] = {0x3f3f3f3f , 0x3f3f3f3f};
            if(j==0) dp[i][j] = update(dp[i-1][j] , K[i-1]);
            else if(i==0) dp[i][j] = update(dp[i][j-1] , L[j-1]);
            else {
                pair<int,int> a = update(dp[i-1][j] , K[i-1]);
                pair<int,int> b = update(dp[i][j-1] , L[j-1]);

                if(a.first < b.first){
                    dp[i][j] = a;
                }else{
                    if(a.first==b.first && a.second<b.second)dp[i][j] = a;
                    else dp[i][j] = b;
                }
                //dp[i][j] = {0,0};
            }
        }
    }

    cout << dp[N][N].first+1 << "\n" << dp[N][N].second;
    return 0;
}
