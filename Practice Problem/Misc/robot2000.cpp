#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    string s; cin >> s;
    int dir=0; //0 = North , 1 = East , ....

    for(auto c : s){
        if(c=='N' && dir!=0){
            if(dir==3)cout << "R";
            if(dir==2)cout << "RR";
            if(dir==1)cout << "RRR";
            dir=0;
        }else if(c=='S' && dir!=2){
            if(dir==1)cout << "R";
            if(dir==0)cout << "RR";
            if(dir==3)cout << "RRR";
            dir=2;
        }else if(c=='E' && dir!=1){
            if(dir==0)cout << "R";
            if(dir==3)cout << "RR";
            if(dir==2)cout << "RRR";
            dir=1;
        }else if(c=='W' && dir!=3){
            if(dir==2)cout << "R";
            if(dir==1)cout << "RR";
            if(dir==0)cout << "RRR";
            dir=3;
        }else if(c=='Z'){
            cout << 'Z';
            dir=0;
            continue;
        }
        cout << 'F';
    }

    return 0;
}
