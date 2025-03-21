#include <iostream>
using namespace std;
struct Point {
    int x;
    int y;
};

// Given three collinear points p, q, I, the function checks if
// point q lies on line segment 'pr'
bool onSegment (Point p, Point q, Point r){

    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
    q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
    return true;

    return false;
 }
// To find orientation of ordered triplet (p, 9, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation (Point p, Point q, Point r){

    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // collinear

    return (val > 0)? 1: 2; // clock or counterclock wise
 }

 bool doIntersect (Point p1, Point q1, Point p2, Point q2){
// Find the four orientations needed for general and
// special cases
int o1 = orientation (p1, q1, p2) ;
int o2 = orientation (p1, q1, q2);
int o3 = orientation(p2, q2, p1);
int o4 = orientation(p2, q2, q1);
// General case
if (o1 != o2 && o3 != o4)
return true;
// Special Cases
// p1, ql and p2 are collinear and p2 lies on segment plal
if (o1 == 0 && onSegment (p1, p2, q1)) return true;
// p1, ql and q2 are collinear and 92 lies on segment plal
if (o2 == 0 && onSegment (p1, q2, q1)) return true;
// p2, 92 and p1 are collinear and pl lies on segment p2q2
if (o3 == 0 && onSegment (p2, p1, q2)) return true;
// p2, 92 and ql are collinear and al lies on segment p2q2
if (o4 == 0 && onSegment (p2, q1, q2)) return true;
return false; // Doesn't fall in any of the above cases
}

int main(){
    struct Point p1 = {1,1}, q1 ={10,1};
    struct Point p2 = {1,2}, q2 ={10,2};

    doIntersect (p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {10, 0}, q1 = {10, 10};
    p2 = {0, 0}, q2 = {10, 10};
    doIntersect (p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    doIntersect (p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
}