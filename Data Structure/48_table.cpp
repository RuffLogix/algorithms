#include <bits/stdc++.h>

using namespace std;

pair<int,int> mem[301][5001];
pair<int,int> row[301];
priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> qq;
pair<int,int> ti[301];

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n,m,k; cin >> n >> m >> k;

    for(int i=0 ; i<k ; i++){
        int x; cin >> x;
        if(x==1){
            int r,c,X ; cin >> r >> c >> X;
            if(mem[r][c].second < ti[r].second){
                ti[r].first++;
            }
            mem[r][c] = {X,i};
            qq.push({X , {r,c}});
        }else if(x==2){
            int r,X; cin >> r >> X;
            row[r] = {X,i};
            qq.push({X , {r,-1}});
            ti[r] = {0,i};
        }else if(x==3){
            int r,c; cin >> r >> c;
            if(mem[r][c].second > row[r].second){
                cout << mem[r][c].first << "\n";
            }else{
                cout << row[r].first << "\n";
            }
        }else if(x==4){
            bool ischange = false;
            while(true){
                ischange=false;
                if(qq.empty()){cout << "0\n";break;}
                if(qq.top().second.second!=-1){
                    if((mem[qq.top().second.first][qq.top().second.second].first!=qq.top().first) || (mem[qq.top().second.first][qq.top().second.second].first==qq.top().first && mem[qq.top().second.first][qq.top().second.second].second<row[qq.top().second.first].second)){
                        ischange = true;
                        qq.pop();
                    }
                }
                if(qq.top().second.second==-1){
                    if(ti[qq.top().second.first].first==m){
                        ischange = true;
                        qq.pop();
                    }else if(row[qq.top().second.first].first!=qq.top().first){
                        ischange = true;
                        qq.pop();
                    }
                }
                if(!ischange){
                    //cout << qq.top().second.first << " " << qq.top().second.second << "\n";
                    cout << qq.top().first << "\n";break;
                }
            }
        }
    }

    return 0;
}