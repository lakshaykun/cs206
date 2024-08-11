#include<iostream>
#include<cassert>
#include "../include/geometry.hpp"
#include <cmath>
using namespace std;


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
	assert(crossProduct({0,1},{1,100},{100,2})==9703);
	assert(crossProduct({7,5},{5,15},{5,4})==22);
	assert(crossProduct({1,2},{3,4},{5,6})==8);
	assert(crossProduct({15,7},{8,7},{10,9})==-14);
    std::cout<<"all test cases passed"<<std::endl;
}
void test_duplicate(){
	

}

void test_perimeter(){
}
	
	
	

int main(){
	cout<<(double)dist({0,0},{1,1})-sqrt(2)<<endl;
	cout<<sqrt(2)<<endl;
	test_distsq();
	test_orientation();
	test_crossproduct();
	return 0;
}

