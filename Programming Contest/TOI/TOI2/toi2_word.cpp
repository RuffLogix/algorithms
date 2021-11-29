#include <bits/stdc++.h>

using namespace std;

char word[26][26];
int x,y;

int dirX[] = {1,1,-1,-1,0,0,1,-1};
int dirY[] = {1,-1,1,-1,1,-1,0,0};

bool solve(int xx,int yy,string s,int idx,int dir){
    if(idx==s.length())return true;
    if(xx<0 || yy<0 || xx>=x || yy>=y)return false;
    if(s[idx]!=word[xx][yy])return false;
    
    return false || solve(xx+dirX[dir] , yy+dirY[dir] , s , idx+1 , dir);    
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> x >> y;

    for(int i=0 ; i<x ; i++){
        for(int j=0 ; j<y ; j++){
            cin >> word[i][j];
            word[i][j] = tolower(word[i][j]);
        }
    }

    int n; cin >> n;

    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        for(int j=0 ; j<s.length() ; j++){
            s[j] = tolower(s[j]);
        }

        for(int i=0 ; i<x ; i++){
            for(int j=0 ; j<y ; j++){
                if(solve(i,j,s,0,0) || solve(i,j,s,0,1) || solve(i,j,s,0,2) || solve(i,j,s,0,3) || solve(i,j,s,0,4) || solve(i,j,s,0,5) || solve(i,j,s,0,6) || solve(i,j,s,0,7)){
                    cout << i << " " << j << "\n";
                    i=x , j=y;
                    break;
                }
            }
        }
    }

    return 0;
}
