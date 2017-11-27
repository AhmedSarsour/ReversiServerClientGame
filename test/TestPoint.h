//
// Created by eliad1998 on 27/11/17.
//

#ifndef TESTPOINT_H
#define TESTPOINT_H

#include "gtest/gtest.h"
#include "../src/Point.h"
//
// Created by eliad1998 on 27/11/17.
//

class TestPoint: public testing::Test {
protected:
    Point p;
public:
    //We take for example 2,3.
    TestPoint() : p(Point(2,3)) {
    }

};


#endif //REVERSITESTS_TESTBOARD_H
