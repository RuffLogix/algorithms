#include <bits/stdc++.h>

using namespace std;

struct Query{
    int L,R;
};

void solve(int arr[] , int n , Query q[] , int m){
    sort(q , q+m , [&](Query a , Query b){
            if(a.L != b.L) return a.L < b.L;
            return a.R < b.R;
         });

    int currL=0 , currR=0;
    int sum=0;
    for(int i=0 ; i<m ; i++){
        int L=q[i].L , R=q[i].R;

        while(currL < L){
            sum -= arr[currL++];
        }

        while(currL > L){
            sum += arr[currL-1];
            currL--;
        }

        while(currR <= R){
            sum += arr[currR++];
        }

        while(currR > R+1){
            sum -= arr[currR-1];
            currR--;
        }

        cout << sum << "\n";
    }
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q)/sizeof(q[0]);

    solve(arr , n , q , m);

    return 0;
}
