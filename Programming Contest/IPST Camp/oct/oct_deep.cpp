#include <bits/stdc++.h>

using namespace std;

int arr[200001][2];
int l,s,a,b ;

int pseudo_random(){
    int res = ((s & 8) >> 3);
    s = (s * a+b) % 40507;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0); 

    int n,k; cin >> n >> k;

    for(int i=0 ; i<n ; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i=0 ; i<k ; i++){
        cin >> l >> s >> a >> b;
        int root = 0; 
        while(true){
            int dir = pseudo_random();
            if((arr[root][0]==-1 && arr[root][1]==-1) || l==0){
                cout << root << "\n";
                break;
            }

            
            if(arr[root][0]!=-1 && arr[root][1]!=-1){
                if(dir==0){
                    root = arr[root][0];
                }else if(dir==1){
                    root = arr[root][1];
                }
            }else{
                if(arr[root][0]!=-1){
                    root = arr[root][0];
                }else if(arr[root][1]!=-1){
                    root = arr[root][1];
                }
            }

            l--;
        }
    }

    return 0;
}