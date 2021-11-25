#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    string s; cin >> s;

    int a=0,b=0,c=0,d=0;
    for(auto cc : s){
        if(cc=='N')a++;
        else if(cc=='S')b++;
        else if(cc=='W')d++;
        else c++;
    }

    int k; cin >> k;

    int mx=0,mn=0;
    mx=max(a,b) + max(c,d);
    mn=min(a,b) + min(c,d);

    mn-=k;
    if(mn<0)mx-=abs(mn),mn=0;

    cout << 2*(mx-mn);
    return 0;
}
