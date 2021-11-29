#include <bits/stdc++.h>

using namespace std;

int getPrior(char c){
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    string s = "a+b*(c^d-e)^(f+g*h)-i";
    stack<char> ss;

    string ans = "";
    for(auto c : s){
        if(c>='a' && c<='z'){
            ans += c;
        }else if(c=='('){
            ss.push(c);
        }else if(c==')'){
            while(!ss.empty() && ss.top()!='('){
                ans+=ss.top(); ss.pop();
            }
            ss.pop();
        }else {
            while(!ss.empty() && getPrior(ss.top()) >= getPrior(c)){
                ans+=ss.top(); ss.pop();
            }
            ss.push(c);
        }
    }

    while(!ss.empty()){
        ans+=ss.top(); ss.pop();
    }

    cout << ans;
    
    return 0;
}