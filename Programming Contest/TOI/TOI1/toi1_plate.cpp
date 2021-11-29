#include <bits/stdc++.h>

using namespace std;

queue<int> qs[11];
queue<int> qc;

unordered_map<int,int> student;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int Nc , Ns; cin >> Nc >> Ns;

    for(int i=0 ; i<Ns ; i++){
        int c,s; cin >> c >> s;
        student[s] = c;
    }

    while(true){
        char cmd ; cin >> cmd;
        if(cmd=='X')break;
        else if(cmd=='E'){
            int x; cin >> x;
            if(qs[student[x]].empty()){
                qc.push(student[x]);
            }
            qs[student[x]].push(x);
        }else if(cmd=='D'){
            cout << qs[qc.front()].front() << "\n";
            qs[qc.front()].pop();
            if(qs[qc.front()].empty())qc.pop();
        }
    }

    cout << 0;
    return 0;
}