/*
 * Point.cpp
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#include "Point.h"
#include <iostream>
/**
 * Point Constructor.
 * function: build the point, saves the x and y values.
 */
Point::Point(int x1, int y1) {
	this->x = x1;
	this->y = y1;
}

/**
 * getX function.
 * @return: int.
 * function: returns the x value of the point.
 */
int Point::getX() const {
	return x;
}

/**
 * setX function.
 * @Param: int.
 * function: sets the new x value of the point.
 */
void Point::setX(int x) {
	this->x = x;
}

/**
 * getY function.
 * @return: int.
 * function: returns the y value of the point.
 */
int Point::getY() const {
	return y;
}
/**
 * equals function.
 * @param other.
 * @return bool.
 * function: checks if this point equals other point, returns true if so,
 * false otherwise.
 */
bool Point::equals(Point other) {
	if (this->x == other.getX() && this->y == other.getY()) {
		return true;
	}
	return false;
}
/**
 * toString function.
 * function: prints the point in a proper way.
 */
void Point::toString() {
	std::cout << "(" << this->getX() << "," << this->getY() << ")";
}

/**
 * setY function.
 * @Param: int.
 * function: sets the new y value of the point.
 */
void Point::setY(int y) {
	this->y = y;
}

ostream &operator <<(ostream &out, const Point &p)
{
	out << "(" << p.getX() << "," << p.getY() << ")";
	return out;
}