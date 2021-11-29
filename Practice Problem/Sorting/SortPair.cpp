#include <bits/stdc++.h>

using namespace std;

struct coor{
    int x,y;
    bool operator<(const coor&x2){
        if(x==x2.x)return y<x2.y;
        return x<x2.x;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n; cin >> n;
    coor arr[n];

    for(int i=0 ; i<n ; i++){
        int a,b; cin >> a >> b;
        arr[i] = {a,b};
    }

    sort(arr,arr+n);

    for(int i=0 ; i<n ; i++){
        cout << arr[i].x << " " << arr[i].y << "\n";
     }

    return 0;
}
/*
5
1 4
4 3
3 8
4 1
5 2
*/
