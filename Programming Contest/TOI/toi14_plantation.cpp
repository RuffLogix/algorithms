#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x,y;
    bool operator < (const Point&p){
        if(x==p.x)return y<p.y;
        return x<p.x;
    }

    double operator - (const Point&p){
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }
};

int n,r,d;

double solve(int l,int r,Point arr[]){
    if(l==r)return 0x3f3f3f3f;
    if(l+1==r)return arr[l]-arr[r];

    int m = (l+r)>>1;
    double d = 0x3f3f3f3f;
    d = min(d,solve(l,m,arr));
    d = min(d,solve(m+1,r,arr));

    for(int i=max(l-8,0) ; i<min(r+9,n) ; i++){
        if(i!=m) d = min(d,arr[i]-arr[m]);
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int t; cin >> t;

    while(t--){
        cin >> n >> r >> d;
        Point arr[n];

        for(int i=0 ; i<n ; i++){
            cin >> arr[i].x >> arr[i].y;
        }

        sort(arr,arr+n);

        if(solve(0,n-1,arr)-r*2 < d){
            cout << "N\n";
        }else{
            cout << "Y\n";
        }
    }

    return 0;
}