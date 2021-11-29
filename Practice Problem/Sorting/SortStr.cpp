#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n; cin >> n;
    string arr[n];

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
hello
hero
helloworld
ant
bat
*/
