#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
bool visited[100001][2];
string s;
int n,U,V;
int ans=0;
void solve(int u,int p,string ss,int k,int l,int r){
    while(l>=r && l!=0 && r!=0){l--,r--;}
    if(r==1 && l==0)return;
    if(u==V){
        if(k!=0){
            if(!visited[p][k-1]){
                //visited[p][k-1] = true;
                //solve(p,u,ss+=s[p-1],k-1,l+int(s[p-1]=='('),r+int(s[p-1]==')'));
                //cout << "hi";
                ans++;
            }
        }
        if(k!=0 || l!=r)return;
        //cout << l << " " << r << "\n";
        //cout << ss << "\n";
        ans++;
        return;
    }
    visited[u][k] = true;

    for(auto v : adj[u]){
        if(!visited[v][k]){
            //cout << u << " -> " << v << "\n";
            solve(v,u,ss+s[v-1],k,l+int(s[v-1]=='('),r+int(s[v-1]==')'));
        }
    }

    if(k!=0){
        for(int v=1 ; v<=n ; v++){
            //cout << u << " -> " << v << "\n";
            if(!visited[v][k-1]){
                solve(v,u,ss+s[v-1],k-1,l+int(s[v-1]=='('),r+int(s[v-1]==')'));
            }
        }
    }

    visited[u][k] = false;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> n >> U >> V;

    for(int i=0 ; i<n-1 ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> s;

    string start="";
    solve(U,-1,start+=s[U-1],1,int(s[U-1]=='('),int(s[U-1]==')'));

    cout << ans;
    return 0;
}
