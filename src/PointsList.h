/*
 * PointsList.h
 *
 *  Created on: Oct 30, 2017
 *      Author: Ahmed sarsour.
 *      Student ID:315397059.
 */
#ifndef POINTSLIST_H_
#define POINTSLIST_H_

#include <list>
#include "Point.h"
using namespace std;


class PointsList {
public:
	//definitions are on PointsList.cpp file.
	PointsList();
	void addPoint(Point p);
	bool checkifContains(Point p);
	void runOnElms();
	list<Point>& getMyList();
	void setMyList(const list<Point>& myList);
	void clearList();

private:
	list<Point> myList;
};

#endif /* POINTSLIST_H_ */
