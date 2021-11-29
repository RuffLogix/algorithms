#include <bits/stdc++.h>

using namespace std;

int a,b,n;

int solve(int x){
    if(x<=0)return abs(x);

    int ans=0x3f3f3f3f;
    ans = min(ans , min(solve(x-a) , solve(x-b)));

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> a >> b >> n;

    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        cout << x+solve(x) << "\n";
    }

    return 0;
}
/*
10 15 4
17
60
47
44
*/
