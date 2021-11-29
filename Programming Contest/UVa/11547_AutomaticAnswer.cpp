#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        cout << abs((((63*n+7492)*5-498)/10)%10) << "\n";
    }

    return 0;
}