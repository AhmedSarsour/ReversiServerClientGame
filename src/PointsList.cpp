/*
 * PointsList.cpp
 * student 1: ahmed sarsour. 315397059
 * student 2: Eliad Arzuan 206482622
 */

#include "PointsList.h"
#include <iostream>
#include <list>
#include "Point.h"
using namespace std;
/**
 * PointsList Constructor.
 */
PointsList::PointsList() {
}
/**
 *runOnElms function.
 *function: it runs on the elements of the points list and prints them.
 */
void PointsList::runOnElms() {
	list<Point>::iterator it;
	list<Point>::iterator it2;
	it2 = this->myList.begin();
	it2++;
	for(it = this->myList.begin(); it != this->myList.end(); it++,it2++){
		it->toString();
		if(it2 != this->myList.end()) {
			cout << ",";
		}
	}
}
/**
 * addPoint function.
 * @param p.
 * function: it adds a point to the list of points.
 */
void PointsList::addPoint(Point p) {
	this->myList.push_back(p);
}
/**
 * checkifContains function.
 * @param p.
 * @return bool.
 * function: it checks if the given point is inside of the points
 * list, returns true if so, false otherwise.
 */
bool PointsList::checkifContains(Point p) {
	list<Point> ::iterator it;
	it = this->myList.begin();
	for (it = this->myList.begin(); it != this->myList.end(); it++) {
		if (it->getX() == p.getX() && it->getY() == p.getY()) {
			return true;
		}
	}
	return false;
}
/**
 * getMyList function.
 * @return list<Point>.
 * function: returns a reference to the points list.
 */
list<Point>& PointsList::getMyList(){
	return this->myList;
}
/**
 *setMyList function.
 * @param list<point>
 * function: sets a list of points.
 */
void PointsList::setMyList(const list<Point>& myList) {
		this->myList = myList;
}
/**
 * clearList function.
 * function: clears the points list.
 */
void PointsList::clearList(){
	this->myList.clear();
}
