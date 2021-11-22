#include <bits/stdc++.h>

using namespace std;

bitset<100001> isprime;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n = 1e9+7;

    isprime.flip();
    isprime[0] = isprime[1] = false;

    vector<int> prime;
    for(int i=2 ; i<=100000 ; i++){
        if(!isprime[i])continue;
        for(int j=i*2 ; j<=100000 ; j+=i){
            isprime[j] = false;
        }
        prime.push_back(i);
    }

    bool isPrime = true;
    for(auto x : prime){
        if(x*x > n)break;
        if(n%x==0){
            isPrime = false;
        }
    }

    if(isPrime){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

    return 0;    
}