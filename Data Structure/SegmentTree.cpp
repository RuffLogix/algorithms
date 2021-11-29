#include <bits/stdc++.h>

#define N 1001

using namespace std;

int tree[N];
int arr[] = {0,1,2,3,4,5,6,7,8};

void build(int l,int r,int t){
    if(l==r){
        tree[t] = arr[l];
    }else{
        int m = (l+r)>>1;
        build(l,m,t*2);
        build(m+1,r,t*2+1);

        tree[t] = tree[t*2] + tree[t*2+1];
    }
}

void update(int idx,int v,int l,int r,int t){
    if(l==r){
        tree[t] = v;
    }else{
        int m = (l+r)>>1;
        
        if(idx<=m){
            update(idx,v,l,m,t*2);
        }else{
            update(idx,v,m+1,r,t*2+1);
        }

        tree[t] = tree[t*2] + tree[t*2+1];
    }
}

int query(int l,int r,int ll,int rr,int t){
    if(rr<l || r<ll)return 0;
    if(ll<=l && r<=rr)return tree[t];

    int m = (l+r)>>1;
    return query(l,m,ll,rr,t*2) + query(m+1,r,ll,rr,t*2+1);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n = sizeof(arr) / sizeof(arr[0]);

    build(1,n,1);
    update(1,10,1,n,1);
    cout << query(1,n,1,n,1);

    return 0;
}