#include <bits/stdc++.h>

using namespace std;

long long int arr[1000001];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    long long int m,n; cin >> m >> n;

    for(int i=0 ; i<m ; i++){
        cin >> arr[i];
    }

    long long int l=1 , r=1e12;
    while(l<r){
        long long int mid = (l+r)>>1;
        long long int sum = 0; 

        for(int i=0 ; i<m ; i++)sum += mid/arr[i];

        sum>=n ? r=mid : l=mid+1;
    }

    cout << l;

    return 0;
}