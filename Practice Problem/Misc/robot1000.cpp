#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    string s; cin >> s;

    int x=0,y=0;
    for(auto c : s){
        if(c=='N')x++;
        else if(c=='S')x--;
        else if(c=='E')y++;
        else if(c=='W')y--;
        else x=0,y=0;
    }

    cout << y << " " << x;

    return 0;
}
