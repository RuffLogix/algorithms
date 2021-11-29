#include <bits/stdc++.h>

using namespace std;

struct cell{
    int a,b,c;
    bool operator < (const cell&cc){
        if(b==cc.b)return a<cc.a;
        return b<cc.b;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int row; cin >> row;
    string s; cin >> s;
    int n = s.length();

    int x=0,y=0;
    vector<cell> v;
    int dirY = 1;
    for(int i=0 ; i<n ; i++){
        //cout << x << " " << y << "\n";
        v.push_back({x,y,i});
        x += 1;
        y += dirY;
        if(y==row){
            dirY=-1;
            y=row-2;
        }
        if(y==-1){
            dirY=1;
            y=1;
        }
    }

    sort(v.begin() , v.end());

    char out[101];
    for(int i=0 ; i<n+1 ; i++){
        if(i==n) out[i] = ' ';
        else out[v[i].c] = s[i];
    }
    
    cout << out;
    return 0;
}