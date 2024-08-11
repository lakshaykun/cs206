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
	std::cout<<"all test cases passed"<<std::endl;
}
void test_orientation(){
	assert(orientation({0,0},{1,1},{3,2})==1);
	assert(orientation({0,0},{1,1},{1,-1})==1);
	assert(orientation({0,0},{0,0},{1,1})==0);
	assert(orientation({1,-1},{1,1},{-1,1})==2);
	assert(orientation({-1,-1},{1,1},{3,3})==0);
    std::cout<<"all test cases passed"<<std::endl;
}
void test_crossproduct(){
	assert(crossProduct({1,1},{1,1},{1,1})==0);
	assert(crossProduct({1,1},{-1,1},{1,-1})==4);
	assert(crossProduct({0,1},{1,100},{100,2})==-9899);
	assert(crossProduct({7,5},{5,15},{5,4})==22);
	assert(crossProduct({1,2},{3,4},{5,6})==0);
	assert(crossProduct({15,7},{8,7},{10,9})==-14);
    std::cout<<"all test cases passed"<<std::endl;
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

    std::cout << "All tests passed!" << std::endl;
}	



void test_perimeter(){
    vector<Point> emptyPolygon;
    assert(fabs(perimeterPolygon(emptyPolygon) - 0.0) < epsilon);

    vector<Point> singlePoint = { {0, 0} };
    assert(fabs(perimeterPolygon(singlePoint) - 0.0) < epsilon);

    vector<Point> twoPoints = { {0, 0}, {1, 1} };
    double expectedPerimeterTwoPoints = 2 * dist({0, 0}, {1, 1});
    assert(fabs(perimeterPolygon(twoPoints) - expectedPerimeterTwoPoints) < epsilon);

    vector<Point> triangle = { {0, 0}, {1, 0}, {0, 1} };
    double expectedPerimeterTriangle = dist({0, 0}, {1, 0}) +
                                       dist({1, 0}, {0, 1}) +
                                       dist({0, 1}, {0, 0});
    assert(fabs(perimeterPolygon(triangle) - expectedPerimeterTriangle) < epsilon);

    vector<Point> collinearPoints = { {0, 0}, {1, 1}, {2, 2} };
    double expectedPerimeterCollinear = 2 * dist({0, 0}, {2, 2});
    assert(fabs(perimeterPolygon(collinearPoints) - expectedPerimeterCollinear) < epsilon);

    vector<Point> largeCoords = { {1000000, 0}, {0, 1000000},
                                  {-1000000, 0}, {0, -1000000} };
    double expectedPerimeterLargeCoords = dist({1000000, 0}, {0, 1000000}) +
                                          dist({0, 1000000}, {-1000000, 0}) +
                                          dist({-1000000, 0}, {0, -1000000}) +
                                          dist({0, -1000000}, {1000000, 0});
    assert(fabs(perimeterPolygon(largeCoords) - expectedPerimeterLargeCoords) < epsilon);

    vector<Point> square = { {0, 0}, {1, 0}, {1, 1}, {0, 1} };
    assert(fabs(perimeterPolygon(square) - 4.0) < epsilon);

    vector<Point> repeatedPoints = { {0, 0}, {1, 0}, {1, 0}, {0, 0} };
    assert(fabs(perimeterPolygon(repeatedPoints) - 2.0) < epsilon);
}

	
	
	

int main(){
	cout<<(double)dist({0,0},{1,1})-sqrt(2)<<endl;
	cout<<sqrt(2)<<endl;
	test_distsq();
	test_orientation();
	test_crossproduct();
	test_duplicate();
    test_perimeter();
	return 0;
}

