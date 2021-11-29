#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n; cin >> n;

    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        bool isV = false;
        int ans=0;
        for(auto c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                if(!isV)ans++;
                isV = true;
            }else{
                isV = false;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
/*
4
hello
already
computer
seal
*/
