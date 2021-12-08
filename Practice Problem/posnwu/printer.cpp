#include <bits/stdc++.h>

using namespace std;

list<string> s;
auto ptr = s.begin();

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;

    for(int i=0 ; i<n ; i++){
        char cmd; cin >> cmd;
        if(cmd=='l'){
            if(ptr!=s.begin()){
                advance(ptr , -1);
            }
        }else if(cmd=='r'){
            auto tmp=ptr;
            advance(tmp , 1);
            if(tmp!=s.end()){
                advance(ptr , 1);
            }
        }else if(cmd=='i'){
            
        }else if(cmd=='b'){
            
        }else if(cmd=='d'){
            
        }
    }

    return 0;
}