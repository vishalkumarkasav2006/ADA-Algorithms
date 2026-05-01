#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
    int x,y;};
int cross(Point O,Point A,Point B) {
    return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);}
int main() {
    vector<Point> pts={
        {0,3},{2,2},{1,1},{2,1},{3,0},{0,0},{3,3}};
    int n=pts.size();
    sort(pts.begin(),pts.end(),[](Point a,Point b) {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;});
    vector<Point> hull;
    for(int i=0;i<n;i++) {
        while(hull.size()>=2&&cross(hull[hull.size()-2],hull[hull.size()-1],pts[i])<=0) {
            hull.pop_back();}
        hull.push_back(pts[i]);}
    int lowerSize=hull.size();
    for(int i=n-2;i>=0;i--) {
        while(hull.size()>lowerSize&&cross(hull[hull.size()-2],hull[hull.size()-1],pts[i])<=0) {
            hull.pop_back();}
        hull.push_back(pts[i]);}
    hull.pop_back();
    cout<<"Convex Hull Points\n";
    for(auto p:hull) {
        cout<<"("<<p.x<<","<<p.y<<")\n";}
    return 0;
}