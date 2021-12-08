#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int parent[100001];

int f(int k){
    if(parent[k]==0 || parent[k]==k)return k;
    return parent[k] = f(parent[k]);
}

int main(){
    ios_base::sync_with_stdio(0);

    int N,M; cin >> N >> M;

    for(int i=1 ; i<=N ; i++){
        cin >> arr[i];
    }

    for(int i=0 ; i<M ; i++){
        int a,b; cin >> a >> b; a = f(a) , b = f(b); 
        if(a==b){
            cout << "-1\n";
        }else{
            if(a>b)swap(a,b) ; //a < b;
            if(arr[a]>=arr[b]){
                arr[a]+=arr[b]/2;
                parent[b] = a;
                cout << a << "\n";
            }else{
                arr[b]+=arr[a]/2;
                parent[a] = b;
                cout << b << "\n";
            }
        }
    }

    return 0;
}