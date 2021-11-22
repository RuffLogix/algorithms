#include <bits/stdc++.h>

using namespace std;

int tree[10000];
int n;

void add(int idx,int x){
    for( ; idx<=n ; idx += (idx&-idx)){
        tree[idx] += x;
    }
}

int getSum(int idx){
    int ans=0;
    for( ; idx>0 ; idx -= (idx&-idx)){
        ans += tree[idx];
    }
    return ans;
}

int getSum(int l,int r){
    return getSum(r) - getSum(l-1);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {1,2,3,4,5,6,7,8};
    n = sizeof(arr) / sizeof(arr[0]);

    for(int i=0 ; i<n ; i++){
        add(i+1,arr[i]);
    }

    cout << getSum(4,8);

    return 0;
}