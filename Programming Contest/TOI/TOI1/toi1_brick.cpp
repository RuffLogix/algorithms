#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int x,y; cin >> x >> y;

    char brick[x][y];
    for(int i=0 ; i<x ; i++){
        for(int j=0 ; j<y ; j++){
            cin >> brick[i][j];
        }
    }

    for(int k=0 ; k<y ; k++){
        int inp , i=0; cin >> inp;
        
        for( ; i<x ; i++){
            if(brick[i][k]=='O')break;
        }
        --i;
        for( ; i>=0 && inp>0 ; i--){
            brick[i][k] = '#';
            inp--;
        }
    }

    for(int i=0 ; i<x ; i++){
        for(int j=0 ; j<y ; j++){
            cout << brick[i][j] ;
        }
        cout << "\n";
    }

    return 0;
}