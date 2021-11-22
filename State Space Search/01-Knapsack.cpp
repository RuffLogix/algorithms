#include <bits/stdc++.h>

using namespace std;

int solve(int sum,int idx,int n,int w[],int v[],int W){
    if(W<0)return 0;
    if(W==0 || idx==n)return sum;

    return max(solve(sum,idx+1,n,w,v,W) , solve(sum+v[idx],idx+1,n,w,v,W-w[idx]));
}

int main(){
    ios_base::sync_with_stdio(0) , cout.tie(0) , cout.tie(0);

    int v[] = {60 , 100 , 120};
    int w[] = {10 , 20 , 30};
    int W = 50 , n = sizeof(w)/sizeof(w[0]);

    cout << solve(0,0,n,w,v,W);

    return 0;
}
