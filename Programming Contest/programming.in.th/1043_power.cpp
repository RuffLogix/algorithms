#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
bitset<100001> isprime;
int solve(int x){
    int ans=0x3f3f3f3f;
    for(auto n : prime){
        if(n*n > x)break;
        int m=0;
        while(x%n==0){m++;x/=n;}
        if(m!=0)ans = min(ans , m);
    }
    if(x!=1)ans = 1;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    //init
    isprime.flip();
    isprime[0] = isprime[1] = false;
    for(int i=2 ; i<=100000 ; i++){
        if(!isprime[i])continue;
        for(int j=i*2 ; j<=100000 ; j+=i){
            isprime[j] = false;
        }
        prime.push_back(i);
    }

    int t;cin >> t;
    
    while(t--){
        int x; cin >> x;
        int ans = solve(x);
        if(ans == 1 || x==1){
            cout << "NO\n";
        }else{
            cout << ans << "\n";
        }
    }
    return 0;
}