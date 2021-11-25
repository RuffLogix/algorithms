#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int P; cin >> P;
    int odd_hp=P , even_hp=P;
    int combo_odd=0 , combo_even=0;
    bool done = false;
    for(int i=0 ; i<P*2 ; i++){
        int x; cin >> x;
        if(done)continue;

        if(x%2==0){combo_even++;combo_odd=0;}
        else {combo_even=0;combo_odd++;}

        if(x%2==0){
            odd_hp-= combo_even>=3 ? 3 : 1;
        }else{
            even_hp-= combo_odd>=3 ? 3 : 1;
        }

        if(odd_hp <= 0){
            cout << 0 << "\n" << x;
            done = true;
        }

        if(even_hp <= 0){
            cout << 1 << "\n" << x;
            done = true;
        }
    }

    return 0;
}
