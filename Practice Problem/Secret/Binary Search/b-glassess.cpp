#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;
    int a[n] , b[n];

    for(int i=0 ; i<n ; i++)cin >> a[i];
    for(int i=0 ; i<n ; i++)cin >> b[i];

    int money; cin >> money;

    int l=0 , r=1e5;
    while(l<r){
        int m = (l+r)>>1;
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += m*a[i] - b[i] < 0 ? 0 : m*a[i] - b[i];
        }

        if(sum > money){
            r = m;
        }else{
            l = m+1;
        }
    }

    cout << l-1;

    return 0;
}
/*
4 
5 2 3 1 
9 9 9 9
25

=> 5
*/