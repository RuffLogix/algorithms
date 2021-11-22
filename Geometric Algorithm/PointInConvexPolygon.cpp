#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x,y;
    Point(){this->x = 0;this->y = 0;}
    Point(int x,int y){this->x = x;this->y = y;}
};

Point Polygon[10];

bool isLeft(Point a,Point b,Point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) >= 0;
}

bool isTriangle(Point a,Point b,Point c,Point x){
    return (((isLeft(x,a,b) == isLeft(x,b,c) ) && isLeft(x,b,c)) == isLeft(x,c,a));
}

bool solve(Point P,int n){
    int l = 1 , r = n-1;
    while(l<=r){
        if(l==r){
            break;
        }

        int mid = (l+r)/2;
        if(isLeft(Polygon[0],Polygon[mid],P))l = mid+1;
        else r=mid;
    }

    return isTriangle(Polygon[0],Polygon[l],Polygon[l+1],P);
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    Polygon[0] = Point(150, 108);
    Polygon[1] = Point(250, 103);
    Polygon[2] = Point(289, 169);
    Polygon[3] = Point(240, 237);
    Polygon[4] = Point(120, 195);

    printf("%s",solve(Point(179,185),4) ? "Yes\n" : "No\n");
    printf("%s",solve(Point(216,90),4) ? "Yes\n" : "No\n");
    printf("%s",solve(Point(129,174),4) ? "Yes\n" : "No\n");

    return 0;
}