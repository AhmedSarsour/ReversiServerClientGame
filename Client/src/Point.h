/*
 * point.h
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
using namespace std;
class Point {
public:
/**
 * Point Constructor.
 * function: build the point, saves the x and y values.
 */
	Point(int x1,int y1);
/**
 * equals function.
 * @param other.
 * @return bool.
 * function: checks if this point equals other point, returns true if so,
 * false otherwise.
 */
	bool equals(Point other);
/**
 * getX function.
 * @return: int.
 * function: returns the x value of the point.
 */
	int getX() const;
/**
 * setX function.
 * @Param: int.
 * function: sets the new x value of the point.
 */
	void setX(int x);
/**
 * getY function.
 * @return: int.
 * function: returns the y value of the point.
 */
	int getY() const;
/**
 * setY function.
 * @Param: int.
 * function: sets the new y value of the point.
 */
	void setY(int y);
/**
 * toString function.
 * function: prints the point in a proper way.
 */
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
