#include <bits/stdc++.h>

using namespace std;

bool foundAns=false;

void solve(int x,int target,string s){
    if(x==target){
        cout << s << "\n";
        foundAns=true;
    }
    if(x==0 || foundAns)return;

    if(x<target)solve(x*2,target,s+="*2");
    solve(x/3,target,s+="/3");
}

int main(){
    ios_base::sync_with_stdio(0) , cout.tie(0) , cout.tie(0);

    int target=120;

    solve(1,target,"1");

    return 0;
}
