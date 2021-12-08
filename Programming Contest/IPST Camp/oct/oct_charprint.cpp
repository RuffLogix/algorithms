#include <bits/stdc++.h>

using namespace std;

queue<int> arr[27];
int tree[300001];
int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int mode; cin >> mode;
    string s1,s2; cin >> s1 >> s2;
    for(int i=0 ; i<s1.length() ; i++){
        arr[s1[i]-'a'].push(i);
    }

    long long int ans=0;
    
    for(int i=0 ; i<s2.length() ; i++){
        if(arr[s2[i]-'a'].size()==0){
            cout << "-1";
            return 0;
        }
        ans += arr[s2[i]-'a'].front() + 1;
        //cout << arr[s2[i]-'a'].front() + 1 << "\n";
        if(mode==1){
            for(int idx=arr[s2[i]-'a'].front()+1 ; idx>0 ; idx-=(idx&-idx)){
                ans-=tree[idx];
            }

            for(int idx=arr[s2[i]-'a'].front()+1 ; idx<=300000 ; idx+=(idx&-idx)){
                tree[idx]+=1;
            }
        }
        arr[s2[i]-'a'].pop();
    }

    cout << ans;

    return 0;
}