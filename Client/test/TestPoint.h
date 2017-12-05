/*
 * student 1: ahmed sarsour. 315397059
 * student 2: Eliad Arzuan 206482622
 */

#ifndef TESTPOINT_H
#define TESTPOINT_H

#include "gtest/gtest.h"
#include "../src/Point.h"
/**
 * TestPoint.
 * Tests if the points function work.
 */

class TestPoint: public testing::Test {
protected:
    Point p;
public:
    /**
     * The constructor.
     * Defining new point for example (2,3) which we will check the functions on.
     */
    TestPoint() : p(Point(2,3)) {
    }

};


#endif //REVERSITESTS_TESTBOARD_H
