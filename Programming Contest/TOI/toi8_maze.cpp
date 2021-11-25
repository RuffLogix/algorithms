#include <bits/stdc++.h>

using namespace std;

struct answer{
    int n,sp;
};

struct position{
    int x,y;
};

int map_pattern[151][151];
int player[151][151];
int target[151][151];

position a,b;
int M,N;

int Xdir[] = {-1,1,0,0};
int Ydir[] = {0,0,1,-1};

bool isValid(int x,int y){
    if(x<0 || y<0 || x>=M || y>=N)return false;
    return true;
}

answer solve(){
    memset(player , 0x3f3f3f3f , sizeof(player));
    memset(target , 0x3f3f3f3f , sizeof(target));

    player[a.x][a.y] = 1;
    target[b.x][b.y] = 1;
    queue<position> q;

    q.push(a);
    while(!q.empty()){
        int x = q.front().x , y = q.front().y ; q.pop();

        for(int i=0 ; i<4 ; i++){
            if(isValid(x+Xdir[i] , y+Ydir[i]) && player[x+Xdir[i]][y+Ydir[i]] > player[x][y] + 1){
                player[x+Xdir[i]][y+Ydir[i]] = player[x][y] + 1;
                if(map_pattern[x+Xdir[i]][y+Ydir[i]]==1)q.push({x+Xdir[i] , y+Ydir[i]});
            }
        }
    }

    q.push(b);
    while(!q.empty()){
        int x = q.front().x , y = q.front().y ; q.pop();

        for(int i=0 ; i<4 ; i++){
            if(isValid(x+Xdir[i] , y+Ydir[i]) && target[x+Xdir[i]][y+Ydir[i]] > target[x][y] + 1){
                target[x+Xdir[i]][y+Ydir[i]] = target[x][y] + 1;
                if(map_pattern[x+Xdir[i]][y+Ydir[i]]==1)q.push({x+Xdir[i] , y+Ydir[i]});
            }
        }
    }

    answer ans = {0,0x3f3f3f3f};
    for(int i=0 ; i<M ; i++){
        for(int j=0 ; j<N ; j++){
            if(player[i][j]!=0x3f3f3f3f && target[i][j]!=0x3f3f3f3f && map_pattern[i][j]==0){
                ans.n++;
                ans.sp = min(ans.sp , player[i][j]+target[i][j]-1);
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> M >> N;


    cin >> a.x >> a.y;
    a.x--,a.y--;
    cin >> b.x >> b.y;
    b.x--,b.y--;

    for(int i=0 ; i<M ; i++){
        for(int j=0 ; j<N ; j++){
            cin >> map_pattern[i][j];
        }
    }

    answer ans = solve();

    cout << ans.n << "\n" << ans.sp;

    return 0;
}
