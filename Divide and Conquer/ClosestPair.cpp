#include <bits/stdc++.h>

using namespace std;

struct Point{
    float x,y;
};

float solve(int l,int r,Point arr[]){
    if(l==r)return 0x3f3f3f3f;
    if(l+1==r)return sqrt((arr[l].x-arr[r].x)*(arr[l].x-arr[r].x) + (arr[l].y-arr[r].y)*(arr[l].y-arr[r].y));

    int m = (l+r)/2;

    float d = min(solve(l,m,arr) , solve(m+1,r,arr));

    l = max(l-16,0);
    r = max(r+16,(int)(sizeof(arr)/sizeof(arr[0])-1));

    for(int i=l ; i<=r ; i++){
        if(i!=m)d = min(d , sqrt((arr[m].x-arr[i].x)*(arr[m].x-arr[i].x) + (arr[m].y-arr[i].y)*(arr[m].y-arr[i].y)));
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    Point arr[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,[&](Point a,Point b){
            if(a.y==b.y)return a.x<b.x;
            return a.y<b.y;
         });

    cout << solve(0,n-1,arr);
    return 0;
}
