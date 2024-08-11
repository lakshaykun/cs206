#include<iostream>
#include<cassert>
#include "../include/geometry.hpp"
#include <cmath>
using namespace std;
const double  epsilon=1e-9;

void test_distsq(){
	assert(dist({0,0},{1,1}) == (double)sqrt(2));
	assert(dist({1,-1},{1,1}) == (double)sqrt(4));
	assert(dist({1,1},{1,1}) == (double)sqrt(0));
	assert(dist({-5,5},{5,-5}) == (double)sqrt(200));
	assert(dist({0,0},{1,0}) == (double)sqrt(1));
	cout<<"all test cases passed"<<endl;
}
void test_orientation(){
	assert(orientation({0,0},{1,1},{3,2})==1);
	assert(orientation({0,0},{1,1},{1,-1})==1);
	assert(orientation({0,0},{0,0},{1,1})==0);
	assert(orientation({1,-1},{1,1},{-1,1})==2);
	assert(orientation({-1,-1},{1,1},{3,3})==0);
    cout<<"all test cases passed"<<endl;
}
void test_crossproduct(){
	assert(crossProduct({1,1},{1,1},{1,1})==0);
	assert(crossProduct({1,1},{-1,1},{1,-1})==4);
	assert(crossProduct({0,1},{1,100},{100,2})==-9899);
	assert(crossProduct({7,5},{5,15},{5,4})==22);
	assert(crossProduct({1,2},{3,4},{5,6})==0);
	assert(crossProduct({15,7},{8,7},{10,9})==-14);
    cout<<"all test cases passed"<<endl;
}
void test_duplicate(){
    
    vector<Point> points1 = {{1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}};
    vector<Point> expected1 = {{1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}};
    removeDuplicates(points1);
    assert(points1 == expected1);

   
    vector<Point> points2 = {{1.0, 1.0}, {1.0, 1.0}, {1.0, 1.0}};
    vector<Point> expected2 = {{1.0, 1.0}};
    removeDuplicates(points2);
    assert(points2 == expected2);

    
    vector<Point> points3 = {{1.0, 1.0}, {2.0, 2.0}, {1.0, 1.0}, {3.0, 3.0}, {2.0, 2.0}};
    vector<Point> expected3 = {{1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}};
    removeDuplicates(points3);
    assert(points3 == expected3);

    
    vector<Point> points4 = {{1.0, 1.0}};
    vector<Point> expected4 = {{1.0, 1.0}};
    removeDuplicates(points4);
    assert(points4 == expected4);


    vector<Point> points5 = {};
    vector<Point> expected5 = {};
    removeDuplicates(points5);
    assert(points5 == expected5);

    cout << "All test cases passed!" << endl;
}
void test_hull() {
    vector<Point> points1 = {{0, 0}, {1, 1}};
    assert(checkHull(points1) == false);

   
    vector<Point> points2 = {{0, 0}, {1, 1}, {2, 2}};
    assert(checkHull(points2) == false);

    vector<Point> points3 = {{0, 0}, {1, 1}, {2, 0}};
    assert(checkHull(points3) == true);

    vector<Point> points4 = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    assert(checkHull(points4) == true);

    vector<Point> points5 = {{0, 0}, {2, 1}, {2, 2}, {0, 2}};
    assert(checkHull(points5) == true);

    vector<Point> points6 = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
    assert(checkHull(points6) == false);

    cout << "All tests cases passed!" << endl;
}	



void test_perimeter(){
        assert((perimeterPolygon(vector<Point>{})==-1));
    assert(perimeterPolygon(vector<Point>{{0, 0}})==-1);
    assert(perimeterPolygon(vector<Point>{{0, 0}, {1, 1}})==-1);
    assert(fabs(perimeterPolygon(vector<Point>{{0, 0}, {1, 0}, {0, 1}}) -
                (dist({0, 0}, {1, 0}) + dist({1, 0}, {0, 1}) + dist({0, 1}, {0, 0}))) < epsilon);
    assert(fabs(perimeterPolygon(vector<Point>{{0, 0}, {2, 0}, {2, 1}, {0, 1}}) -
                (dist({0, 0}, {2, 0}) + dist({2, 0}, {2, 1}) + dist({2, 1}, {0, 1}) + dist({0, 1}, {0, 0}))) < epsilon);
    assert(fabs(perimeterPolygon(vector<Point>{{0, 0}, {1, 0}, {1, 1}, {0, 1}}) - 4.0) < epsilon);
    assert(perimeterPolygon(vector<Point>{{0, 0}, {1, 1}, {2, 2}}) ==-1);
    assert(fabs(perimeterPolygon(vector<Point>{{1000000, 0}, {0, 1000000}, {-1000000, 0}, {0, -1000000}}) -
                (dist({1000000, 0}, {0, 1000000}) +
                 dist({0, 1000000}, {-1000000, 0}) +
                 dist({-1000000, 0}, {0, -1000000}) +
                 dist({0, -1000000}, {1000000, 0}))) < epsilon);
    assert(fabs(perimeterPolygon(vector<Point>{{0, 0}, {2, 0}, {2, 2}, {0, 2}, {0, 0}}) -
                (dist({0, 0}, {2, 0}) + dist({2, 0}, {2, 2}) + dist({2, 2}, {0, 2}) + dist({0, 2}, {0, 0}))) < epsilon);

    cout << "All Test Cases Passed!" << endl;
}

	
void test_area(){
    assert(fabs(areaPolygon({}) - 0.0) < epsilon);

    assert(fabs(areaPolygon({{0, 0}}) - 0.0) < epsilon);

    assert(fabs(areaPolygon({{0, 0}, {1, 1}}) - 0.0) < epsilon);

    assert(fabs(areaPolygon({{0, 0}, {4, 0}, {0, 3}}) - 6.0) < epsilon);

    assert(fabs(areaPolygon({{0, 0}, {1, 0}, {1, 1}, {0, 1}}) - 1.0) < epsilon);

    assert(fabs(areaPolygon({{0, 0}, {2, 0}, {2, 3}, {0, 3}}) - 6.0) < epsilon);
    assert(fabs(areaPolygon({{0, 0}, {1, 1}, {2, 2}}) - 0.0) < epsilon);

    assert(fabs(areaPolygon({{1000000, 0}, {0, 1000000}, {-1000000, 0}, {0, -1000000}}) - (2 * 1e12)) < epsilon);

    assert(fabs(areaPolygon({{0, 0}, {1, 0}, {1, 0}, {0, 0}}) - 0.0) < epsilon);

    cout<<"All Test Cases Passed"<<endl;
}	
	

int main(){

	test_distsq();
	test_orientation();
	test_crossproduct();
	test_duplicate();
    test_perimeter();
    test_hull();
    test_area();
	return 0;
}

