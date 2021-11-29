#include <bits/stdc++.h>

using namespace std;

struct state{
    int x,y;
};

char s[201][201];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n,m; cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> s[i][j];
        }
    }


    return 0;
}