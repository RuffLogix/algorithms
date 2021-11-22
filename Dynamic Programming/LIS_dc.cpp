#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {5,4,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v;
    for(int i=0 ; i<n ; i++){
        if(v.size()==0 || v.back()<arr[i])v.push_back(arr[i]);
        else if(arr[i]<v[0])v[0] = arr[i];
        else {
            v[upper_bound(v.begin(),v.end(),arr[i])-v.begin()] = arr[i];
        }
    }

    cout << v.size();

    return 0;
}
