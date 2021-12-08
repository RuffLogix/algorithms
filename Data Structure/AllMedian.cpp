#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n; cin >> n;
    priority_queue<float> mx;
    priority_queue<float , vector<float> , greater<float>> mn;

    for(int i=0 ; i<n ; i++){
        float x; cin >> x;

        if(mx.empty())mx.push(x);
        else if(mn.empty())mn.push(x);
        else {
            if(mn.top() > x)mx.push(x);
            else mn.push(x);
        }

        if(!mx.empty() && !mn.empty() && mx.top()>mn.top()){
            float a=mx.top(),b=mn.top();
            mx.pop() , mn.pop();
            mn.push(a);
            mx.push(b);
        }

        if(mx.size() >= mn.size()+2){mn.push(mx.top()) ; mx.pop();}
        if(mn.size() >= mx.size()+2){mx.push(mn.top()) ; mn.pop();}

        if(mx.size()==mn.size()){
            printf("%.1f\n",(mx.top()+mn.top())/2.0);
        }else if(mx.size() > mn.size()){
            printf("%.1f\n", mx.top());
        }else{
            printf("%.1f\n", mn.top());
        }
    }

    return 0;
}