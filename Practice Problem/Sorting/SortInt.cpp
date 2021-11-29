#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n; cin >> n;
    int arr[n];

    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    for(int i=0 ; i<n ; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}
/*
5
1
4
3
9
7
*/
