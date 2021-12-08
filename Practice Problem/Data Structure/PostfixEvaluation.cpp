#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    string s; cin >> s;
    stack<int> sc;

    for(auto c : s){
        if(c>='0' && c<='9'){
            sc.push(c-'0');
        }else{
            int a = sc.top(); sc.pop();
            int b = sc.top(); sc.pop();
            int ans;
            if(c=='*')ans = a*b;
            else if(c=='/')ans = b/a;
            else if(c=='+')ans = a+b;
            else if(c=='-')ans = b-a;

            sc.push(ans);
        }
    }

    cout << sc.top();
    return 0;
}