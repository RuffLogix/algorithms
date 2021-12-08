#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        unordered_map<int,int> user;
        int dose1=0 , dose2=0;
        for(int i=0 ; i<n ; i++){
            while(true){
                int x; cin >> x;
                if(x==0)break;
                user[x]++;
                if(user[x]==1)dose1++;
                else dose1--,dose2++;
            }
        }
        cout << dose1 << " " << dose2 << "\n";
    }

    return 0;
}