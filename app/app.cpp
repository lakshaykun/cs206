#include <iostream>
#include <vector>
#include <stack>
#include "../include/gnuplot-iostream.h"
#include "../include/geometry.hpp"

using namespace std;

// function to calculate convex hull of a set of points
vector<Point> convexHull(vector<Point> points, int n);

int main()
{   
    vector<Point> points;
    int n; // no. of points
    cin >> n;

    if (n < 3){
        cout << "Convex Hull not possible with less than 3 points!!!" << endl;
        return 0;
    }

    for (int i=0; i<n; i++){
        Point x;
        cout << "#" << i+1 << ") ";
        cin >> x.first >> x.second;
        points.push_back(x);
    }

    // remove duplicate points
    removeDuplicates(points);

    vector<Point> result = convexHull(points, points.size());
    if (checkHull(result) == false){
        cout << "Convex Hull not possible!!!" << endl;
        return 0;
    }

    double area = areaPolygon(result);

    double perimeter = perimeterPolygon(result);

    cout << "Convex Hull: ";
    for (int i=0; i<result.size(); i++){
        cout << "(" << result[i].first << ", " << result[i].second << ") ";
    }
    cout << endl;
    cout << "Area of Convex Hull: " << area << " unit sq" << endl;
    cout << "Perimeter of Convex Hull: " << perimeter << " unit" << endl;

    // Prepare data for gnuplot
    std::vector<std::pair<double, double>> original_points;
    for (const auto& p : points) {
        original_points.emplace_back(p.first, p.second);
    }

    std::vector<std::pair<double, double>> hull_points;
    for (const auto& p : result) {
        hull_points.emplace_back(p.first, p.second);
    }
    // Close the hull by adding the first point at the end
    hull_points.emplace_back(result.front().first, result.front().second);

    // Plot using gnuplot
    Gnuplot gp;
    gp << "set title 'Convex Hull\n";
    gp << "plot '-' with points pt 7 title 'Points', '-' with lines lw 2 title 'Convex Hull'\n";

    gp.send1d(original_points);
    gp.send1d(hull_points);

    return 0;
}

// function to calculate convex hull of a set of points
vector<Point> convexHull(vector<Point> points, int n){
    // initializing vector for points of convex hull
    vector<Point> hull;
    // checking if there are atleast three points
    if (n<3) return hull;
    // find the leftmost element to start algo with
    int l=0;
    for (int i=0; i<n; i++){
        if (points[l].first > points[i].first){
            l = i;
        }
    } 
    // Start from point l, keep moving counterclockwise
    // until reach the start point again.
    int p = l;   
    do {
        // adding points p into hull
        hull.push_back(points[p]);
        // Search for a point 'q' such that orientation(p, q, x)
        // is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        int q = (p+1)%n;
        for (int i=0; i<n; i++){
            if (orientation(points[p], points[i], points[q]) == 2){
                q = i;
            }
        }
        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;
    } while (p!=l);
    return hull;
}