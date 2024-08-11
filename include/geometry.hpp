#include <iostream>
#include <vector>

using namespace std;

// data type to store points 
typedef pair<double, double> Point;

// function to calculate square of distance between two points
double dist(Point p1, Point p2);

// function to calculate orientation of three points
int orientation(Point p, Point q, Point r);

// function to calculate cross product of pq and qr given triplets p, q, r
double crossProduct(Point p, Point q, Point r);

// function to calulate area of a polygon
double areaPolygon(vector<Point> points);

// function to calculate perimeter of a polygon
double perimeterPolygon(vector<Point> points);

// function to remove duplicate points from the set of points
void removeDuplicates(vector<Point> &points);