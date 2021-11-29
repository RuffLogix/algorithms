#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int arr[] = {1,2,3,5,4,6};
        for(auto c : s){
            if(c=='F'){
                swap(arr[0] , arr[1]);
                swap(arr[0] , arr[5]);
                swap(arr[0] , arr[3]);
            }else if(c=='B'){
                swap(arr[0] , arr[1]);
                swap(arr[1] , arr[5]);
                swap(arr[5] , arr[3]);
            }else if(c=='L'){
                swap(arr[0] , arr[4]);
                swap(arr[4] , arr[5]);
                swap(arr[5] , arr[2]);
            }else if(c=='R'){
                swap(arr[0] , arr[2]);
                swap(arr[2] , arr[5]);
                swap(arr[4] , arr[5]);
            }else if(c=='C'){
                swap(arr[3] , arr[2]);
                swap(arr[2] , arr[4]);
                swap(arr[1] , arr[2]);
            }else if(c=='D'){
                swap(arr[4] , arr[1]);
                swap(arr[3] , arr[1]);
                swap(arr[1] , arr[2]);
            }
        }
        
        cout << arr[1] << " ";
    }

    return 0;
}