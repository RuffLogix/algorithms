#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 9;

    int l=0 , r=n-1;
    while(l<r){
        int m = (l+r)/2;

        if(arr[m] <= x){
            l = m+1;
        }else{
            r = m;
        }
    }

    if(arr[l]!=x){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
    return 0;
}
