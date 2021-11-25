#include <bits/stdc++.h>

using namespace std;

int Ghost[101][101];
int Pacman[101][101];
string s[101];
int R,C,n,T,r,c;

bool isValid(int x,int y){
    if(x>=R || y>=C || x<0 || y<0)return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int t; cin >> t;

    int Xdir[] = {-1,1,0,0};
    int Ydir[] = {0,0,-1,1};

    while(t--){
        memset(Ghost , 0x3f3f3f3f , sizeof(Ghost));
        memset(Pacman , 0x3f3f3f3f , sizeof(Pacman));

        cin >> R >> C >> n >> T >> r >> c; Pacman[r][c] = 0;

        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++){
            int v,a,b; cin >> v >> a >> b;
            Ghost[a][b] = min(Ghost[a][b] , v);
            q.push({a,b});
        }

        for(int i=0 ; i<R ; i++){
            cin >> s[i];
        }

        while(!q.empty()){
            int x=q.front().first,y=q.front().second; q.pop();
            for(int i=0 ; i<4 ; i++){
                if(isValid(x+Xdir[i] , y+Ydir[i]) && Ghost[x+Xdir[i]][y+Ydir[i]] > Ghost[x][y] + 1 && s[x+Xdir[i]][y+Ydir[i]]!='#'){
                    Ghost[x+Xdir[i]][y+Ydir[i]] = Ghost[x][y] + 1;
                    q.push({x+Xdir[i],y+Ydir[i]});
                }
            }
        }

        q.push({r,c});
        bool isSurvived = false;
        while(!q.empty()){
            int x=q.front().first,y=q.front().second; q.pop();
            if(Pacman[x][y] > T)break;
            if(Ghost[x][y] > T){
                isSurvived = true;
                break;
            }
            for(int i=0 ; i<4 ; i++){
                if(isValid(x+Xdir[i] , y+Ydir[i]) && Pacman[x+Xdir[i]][y+Ydir[i]] > Pacman[x][y] + 1 && s[x+Xdir[i]][y+Ydir[i]]!='#'){
                    Pacman[x+Xdir[i]][y+Ydir[i]] = Pacman[x][y] + 1;
                    q.push({x+Xdir[i],y+Ydir[i]});
                }
            }
        }

        isSurvived ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
