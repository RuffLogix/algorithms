#include<bits/stdc++.h>
using namespace std;
int k,l,q;
int base[16][16];
int dist[16][16];
int position[16];

int lca(int a,int b){
    if(a<(1<<k)&&b>(1<<k)) return 1e9;
    if(a>(1<<k)&&b<(1<<k)) return 1e9;
    if(a>(1<<k)&&b>(1<<k)){
        a-=1<<k;
        b-=1<<k;
    }
    int ans=0;
    while(a!=b){
        if(a>b){
            a/=2;
            ans++;
        }else{
            b/=2;
            ans++;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>k>>l>>q;
    for(int i = 0 ; i < 16; i++){
        for(int j = 0; j < 16; j++){
            base[i][j]=1e9;
        }
        base[i][i]=0;
    }

    for(int i = 0; i < l; i++){
        int st,la;
        cin>>st>>la;
        position[2*i]=st;
        position[2*i+1]=la;
        base[i*2][i*2+1]=1;
        base[i*2+1][i*2]=1;
    }
    
    for(int i = 0; i < 2*l; i++){
        for(int j = 0; j < 2*l; j++){
            base[i][j]=min(base[i][j],lca(position[i],position[j]));
        }
    }

    while(q--){
        int st,la;
        cin>>st>>la;
        position[2*l]=st;
        position[2*l+1]=la;
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                dist[i][j]=base[i][j];
            }
        }
        for(int i = 0; i < 2*l; i++){
            dist[2*l][i]=dist[i][2*l]=min(dist[i][2*l],lca(position[i],position[2*l]));
            dist[2*l+1][i]=dist[i][2*l+1]=min(dist[i][2*l+1],lca(position[i],position[2*l+1]));
        }
        dist[2*l][2*l+1]=dist[2*l+1][2*l]=min(dist[2*l][2*l+1],lca(position[2*l],position[2*l+1]));
        for(int k = 0; k < 2*l+2; k++){
            for(int i = 0; i < 2*l+2; i++){
                for(int j = 0; j < 2*l+2; j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        cout<<dist[2*l][2*l+1]<<endl;
    }
    return 0;
}