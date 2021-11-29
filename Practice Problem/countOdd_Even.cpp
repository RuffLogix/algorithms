#include <bits/stdc++.h>

#define N 100000
using namespace std;

int tree[N*4];
int arr[N*4];

void build(int l,int r,int t){
    if(l==r){
        tree[t] = arr[l];
    }else{
        int m = (l+r)/2;
        build(l,m,t*2);
        build(m+1,r,t*2+1);

        tree[t] = tree[t*2] + tree[t*2+1];
    }
}

void update(int idx , int v , int l , int r ,int t){
    if(l==r && idx==l){
        tree[t] = v;
    }else{
        if(l==r)return;
        int m = (l+r)/2;
        if(idx <=m)update(idx,v,l,m,t*2);
        else update(idx,v,m+1,r,t*2+1);

        tree[t] = tree[t*2] + tree[t*2+1];
    }
}

int query(int ll,int rr,int l,int r,int t){
    if(rr<l || r<ll)return 0;
    if(ll<=l && r<=rr)return tree[t];

    int m = (l+r)/2;
    return query(ll,rr,l,m,t*2) + query(ll,rr,m+1,r,t*2+1);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n;cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> arr[i+1];
        arr[i+1] = arr[i+1]%2;
        //arr[i+1] = i%2;
    }

    build(1,n,1);

    int m; cin >> m;
    for(int i=0 ; i<m ; i++){
        int cmd , a , b; cin >> cmd >> a >> b;
        if(cmd == 0){
            update(a,b%2,1,n,1);
        }else if(cmd == 1){
            cout << (b-a+1)-query(a,b,1,n,1) << "\n";
            //for(int i=1 ; i<n*2 ; i++) cout << tree[i] << " ";
            //cout << "\n";
        }else if(cmd == 2){
            cout << query(a,b,1,n,1) << "\n";
        }
    }

    return 0;
}