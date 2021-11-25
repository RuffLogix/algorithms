/*
    Score : 100/100
    Related Topic : Dynamic Programming
*/

#include <bits/stdc++.h>

using namespace std;

struct woody{
    int x,y,c;
};

long long int dp[501][501];
woody arr[1001];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int N,X,Y; cin >> N >> X >> Y;

    for(int i=0 ; i<N ; i++){
        int a,b,c ; cin >> a >> b >> c;
        arr[i] = {a,b,c};
    }

    for(int i=0 ; i<N ; i++){

        for(int a=500 ; a>=0 ; a--){
            for(int b=500 ; b>=0 ; b--){
                if(dp[a][b] || (a==0 && b==0)){
                    //cout << i << " " << a << " " << b << " " << a+arr[i].x << " " << b+arr[i].y << "\n";
                    if(dp[min(a+arr[i].x , X)][min(b+arr[i].y , Y)]==0) dp[min(a+arr[i].x , X)][min(b+arr[i].y , Y)] = 1e15;
                    dp[min(a+arr[i].x , X)][min(b+arr[i].y , Y)] = min(dp[min(a+arr[i].x , X)][min(b+arr[i].y , Y)] , dp[a][b]+arr[i].c);

                }
            }
        }

//        for(int x=0 ; x<=X ; x++){
//
//            for(int j=0 ; j<=Y ; j++){
//                cout << dp[x][j] << " ";
//            }
//            cout << "\n";
//
//        }
//        cout << "==\n";

    }

    if(X==0 && Y==0)dp[X][Y] = 0;
    dp[X][Y] ? cout << dp[X][Y] : cout << "-1";

    return 0;
}
