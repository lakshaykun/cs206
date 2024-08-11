#include <vector>
#include <stack>
#include <cmath>
#include "../include/geometry.hpp"
using namespace std;


//function to calculate square of distance between two points
double dist(Point p1, Point p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

// function to calculate orientation of three points (p, q, r).
int orientation(Point p, Point q, Point r)
{
    int val = crossProduct(p, q, r);
    if (val == 0.0) return 0; // collinear
    return (val < 0.0) ? 1 : 2; // clock or counterclock wise
}

// function to calculate cross product of pq and qr given triplets p, q, r
double crossProduct(Point p, Point q, Point r)
{
    return (q.first - p.first) * (r.second - q.second) - (q.second - p.second) * (r.first - q.first);
}


// function to calulate area of a polygon
double areaPolygon(vector<Point> points)
{
    int n = points.size();
    //initialize area
    double area = 0;

    int j = n-1;
    for (int i=0; i<n; i++){
        area += (points[j].first + points[i].first) * (points[j].second - points[i].second);
        j = i;
    }

    return abs(area / 2);
}

// function to calculate perimeter of a polygon
double perimeterPolygon(vector<Point> points)
{
    int n = points.size();
    double perimeter = 0;
    for (int i=0; i<n; i++){
        perimeter += dist(points[i], points[(i+1)%n]);
    }

    return perimeter;
}

// function to remove duplicate points from the set of points
void removeDuplicates(vector<Point> &points)
{
    for (int i=0; i<points.size(); i++){
        for (int j=i+1; j<points.size(); j++){
            if (points[i] == points[j]){
                points.erase(points.begin() + j);
                j--;
            }
        }
    }
}


// function to check if the convex hull returned by the function is collinear or not
// returns true if the convex hull is not collinear
bool checkHull(vector<Point> points)
{
    int n = points.size();
    if (n < 3) return false;

    for (int i=0; i<n; i++){
        if (orientation(points[i], points[(i+1)%n], points[(i+2)%n]) != 0){
            return true;
        }
    }

    return false;
}
