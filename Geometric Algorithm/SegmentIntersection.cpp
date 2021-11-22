#include <bits/stdc++.h>

using namespace std;

struct Point{
    float x,y;

    Point(){

    }

    Point(float x , float y){
        this->x = x;
        this->y = y;
    }
};

struct Line{
    Point p1 , p2;

    Line(Point p1,Point p2){
        this->p1 = p1;
        this->p2 = p2;
    }
};

float crossProduct(Point a,Point b,Point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool isCollinear(Point a,Point b,Point c){
    return crossProduct(a,b,c) == 0;
}

bool isLeft(Point a,Point b,Point c){
    return crossProduct(a,b,c) > 0;
}

bool isBetween(Point a,Point b,Point c){
    bool isBetweenX = min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x);
    bool isBetweenY = min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y);

    return isBetweenX && isBetweenY;
}

bool isOppositeSide(Point a,Point b,Point c,Point d){
    return (isLeft(a,b,c) != isLeft(a,b,d));
}

bool isSegment(Line l1 , Line l2){
    if(isCollinear(l1.p1,l1.p2,l2.p1) && isBetween(l1.p1,l1.p2,l2.p1))return true;
    if(isCollinear(l1.p1,l1.p2,l2.p2) && isBetween(l1.p1,l1.p2,l2.p1))return true;
    if(isCollinear(l2.p1,l2.p2,l1.p1) && isBetween(l2.p1,l1.p1,l2.p1))return true;
    if(isCollinear(l2.p1,l2.p2,l1.p2) && isBetween(l2.p1,l1.p1,l2.p1))return true;
    
    return (isOppositeSide(l1.p1,l1.p2,l2.p1,l2.p2) && isOppositeSide(l2.p1,l2.p2,l1.p1,l1.p2));
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    Point p1(0.0, 0.0) , p2(0.0, 2.0) , p3(-1.0, 2.0) , p4(1.0, 2.0);
    Line l1(p1,p2) , l2(p3,p4);
    
    printf("%s",isSegment(l1,l2) ? "Yes\n" : "No\n");

    return 0;
}