#include <bits/stdc++.h>

using namespace std;

int getPrior(char c){
    if(c=='^')return 4;
    if(c=='*' || c=='/')return 3;
    if(c=='+' || c=='-')return 2;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    string s; cin >> s;
    stack<char> sc;
    for(auto c : s){
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            cout << c;
        }else if(c=='('){
            sc.push(c);
        }else if(c==')'){
            while(sc.top()!='('){
                cout << sc.top() ; sc.pop();
            }
            sc.pop();
        }else{
            while(!sc.empty() && sc.top()!='(' && getPrior(sc.top()) >= getPrior(c)){
                cout << sc.top() ; sc.pop();
            }
            sc.push(c);
        }
    }

    while(!sc.empty()){
        cout << sc.top(); sc.pop();
    }
    return 0;
}