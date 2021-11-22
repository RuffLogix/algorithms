#include <bits/stdc++.h>

using namespace std;

bitset<100001> is_prime;

int main(){
    ios_base::sync_with_stdio(0) , cout.tie(0) , cin.tie(0);

    is_prime.flip();
    is_prime[0] = is_prime[1] = false;

    for(int i=2 ; i<=100000 ; i++){
        if(!is_prime[i])continue;
        for(int j=i*2 ; j<=100000 ; j+=i){
            is_prime[j] = false;
        }
        cout << i << " ";
    }

    return 0;
}