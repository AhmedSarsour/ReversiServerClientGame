/*
 * PointsList.h
 *
 * student 1: ahmed sarsour. 315397059
 * student 2: Eliad Arzuan 206482622
 */
#ifndef POINTSLIST_H_
#define POINTSLIST_H_

#include <list>
#include "Point.h"
using namespace std;


class PointsList {
public:
	//definitions are on PointsList.cpp file.
    /**
 * PointsList Constructor.
 */
	PointsList();
/**
 * addPoint function.
 * @param p.
 * function: it adds a point to the list of points.
 */
	void addPoint(Point p);
/**
 * checkifContains function.
 * @param p.
 * @return bool.
 * function: it checks if the given point is inside of the points
 * list, returns true if so, false otherwise.
 */
	bool checkifContains(Point p);
/**
 *runOnElms function.
 *function: it runs on the elements of the points list and prints them.
 */
	void runOnElms();
/**
 * getMyList function.
 * @return list<Point>.
 * function: returns a reference to the points list.
 */
    list<Point>& getMyList();
/**
 *setMyList function.
 * @param list<point>
 * function: sets a list of points.
 */
	void setMyList(const list<Point>& myList);
/**
 * clearList function.
 * function: clears the points list.
 */
    void clearList();
	void sortList();

private:
	list<Point> myList;
};

#endif /* POINTSLIST_H_ */
