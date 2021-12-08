#include <bits/stdc++.h>

using namespace std;

bitset<20001> isprime;
vector<int> prime;

int solve(int n){
    int ans=1;
    for(auto x : prime){
        if(x*x > n)break;
        int cnt=0;
        while(n%x==0){cnt++;n/=x;}
        if(cnt && x!=2)ans*=(cnt+1);
    }
    if(n!=1)ans*=2;
    return ans-1;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    isprime.flip();
    isprime[0] = isprime[1] = false;
    for(int i=2 ; i<=20000 ; i++){
        if(!isprime[i])continue;
        for(int j=i*2 ; j<=20000 ; j+=i){
            isprime[j] = false;
        }
        prime.push_back(i);
    }
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        cout << solve(n) << "\n";
    }  

    return 0;
}