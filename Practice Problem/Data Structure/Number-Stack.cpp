#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int n; cin >> n;
    stack<int> sc;

    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        if(s.size()>1 || (s[0]>='0' && s[0]<='9')){
            sc.push(stoi(s));
        }else{
            int a = sc.top(); sc.pop();
            int b = sc.top(); sc.pop();
            int ans;
            if(s[0]=='*')ans = a*b;
            else if(s[0]=='/')ans = b/a;
            else if(s[0]=='+')ans = a+b;
            else if(s[0]=='-')ans = b-a;

            sc.push(ans);
        }
    }

    cout << sc.top();
    return 0;
}