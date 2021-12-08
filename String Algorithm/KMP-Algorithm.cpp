#include <bits/stdc++.h>

using namespace std;

int pi[1001];

void compute_prefix(string s){ // s = pattern string
    int k=0;
    for(int i=1 ; i<s.length() ; i++){
        while(k>0 && s[i]!=s[k]){
            k = pi[k-1];
        }
        if(s[i]==s[k])k++;
        pi[i] = k;
    }
}

void KMP(string txt,string pattern){
    int n = txt.length() , m = pattern.length();

    compute_prefix(pattern);

    int k=0;
    for(int i=0 ; i<txt.length() ; i++){
        while(k>0 && txt[i]!=pattern[k]){
            k = pi[k-1];
        } 
        if(txt[i]==pattern[k]) k++;
        if(k==m){
            for(int j=i-m+1 ; j<=i ; j++){
                cout << txt[j];
            }
            cout << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);

    string txt = "THIS IS A TEST TEXT";
    string pattern = "IS A";

    KMP(txt , pattern);

    return 0;
}