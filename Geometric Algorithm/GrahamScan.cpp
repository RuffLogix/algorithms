#include <bits/stdc++.h>

using namespace std;

struct Point{
    float x,y;

    Point(){
        this->x = 0;
        this->y = 0;
    }

    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

float CCW(Point a,Point b,Point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> grahamScan(Point P[],int n){
    int idx=1;
    for(int i=1 ; i<n ; i++){
        if(P[i].y < P[idx].y || (P[i].y == P[idx].y && P[i].x < P[idx].x)){
            idx = i;
        }
    }

    swap(P[idx],P[1]);
    Point R = P[1];
    sort(P+2,P+n,[&](Point a,Point b){
        return atan2(a.y-R.y,a.x-R.x) < atan2(b.y-R.y,b.x-R.x); 
    });
    
    int hullSize = 1;
    P[0] = P[n-1];

    for(int i=2 ; i<n ; i++){
        while(CCW(P[hullSize-1],P[hullSize],P[i]) <= 0){
            if(hullSize > 1) --hullSize;
            else if(i==n-1) break;
            else {
                i++;
            }
        }

        swap(P[++hullSize],P[i]);
    }

    for(int i=1 ; i<=hullSize ; i++){
        cout << P[i].x << " " << P[i].y << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    Point P[] = {{0,0},{0,0},{1,-4},{-1,-5},{-5,-3},{-3,-1},{-1,-3},{-2,-2},{-1,-1},{-2,-1},{-1,1}};
    int n = sizeof(P)/sizeof(P[0]);

    vector<Point> ans = grahamScan(P,n);

    return 0;
}