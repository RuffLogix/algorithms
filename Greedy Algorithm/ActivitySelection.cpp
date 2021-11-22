#include <bits/stdc++.h>

using namespace std;

class Event{
    public:
        int start,finish;
        Event(){}
        Event(int s,int f){
            start = s;
            finish = f;
        }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    Event e[] = {{1,2} , {3,4} , {0,6} , {5,7} , {8,9} , {5,9}};
    int n = sizeof(e)/sizeof(e[0]);

    sort(e , e+n , [&](Event a,Event b){
            return a.finish < b.finish;
         });

    int ans=0;
    int pre_f=0;
    for(int i=0 ; i<n ; i++){
        if(pre_f<=e[i].start){
            pre_f=e[i].finish;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
