#include <bits/stdc++.h>

using namespace std;

struct bottle{
    int height , idx;
    bool operator < (const bottle&bb){
        if(height==bb.height)return idx<bb.idx;
        return height>bb.height;
    }
};

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n,m; cin >> n >> m;
    bottle arr[n];

    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        arr[i] = {x,i};
    }

    sort(arr,arr+n);

    bool visited[n];
    memset(visited , false , sizeof(visited));
    int idx=0;
    for(int i=0 ; i<m ; i++){
        cin >> m;
        int ans=0;
        while(idx<n && arr[idx].height>m){
            if(!visited[arr[idx].idx]){visited[arr[idx].idx] = true;ans++;}
            if(!visited[max(0,arr[idx].idx-1)]){visited[max(0,arr[idx].idx-1)] = true;ans++;}
            if(!visited[min(n-1,arr[idx].idx+1)]){visited[min(n-1,arr[idx].idx+1)] = true;ans++;}
            idx++;
        }
        cout << ans << "\n";
    }

    return 0;
}
/*
7 4
3
1
4
6
7
3
5
5
4
6
2
*/
