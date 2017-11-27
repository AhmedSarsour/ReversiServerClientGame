/*
 * point.h
 *  Created on: Oct 26, 2017
 *      Author: Ahmed sarsour.
 *      Student ID: 315397059.
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
using namespace std;
class Point {
public:
	Point(int x1,int y1);
	bool equals(Point other);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	void toString();
   /**
     * Override the operator << like toString.
     * @param out - an ostream -like cout
     * @param frac the point we want to print.
     * @return a way to print the point
     */
    friend ostream &operator <<(ostream &out, const Point &frac);

private:
int x;
int y;
};

#endif /* POINT_H_ */
