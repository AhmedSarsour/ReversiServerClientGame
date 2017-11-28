/*
 * student 1: ahmed sarsour. 315397059
 * student 2: Eliad Arzuan 206482622
 */

#ifndef TESTPOINTLIST_H
#define TESTPOINTLIST_H

#include "gtest/gtest.h"
#include "../src/PointsList.h"
/**
 * Class that tests if the PointList functions work.
 */
class TestPointList: public testing::Test {
protected:
    //A list we will check it's functions on.
    PointsList lst;

public:
    /*
     * We will initialize an empty list which we will check the functions on.
     */
    TestPointList() {
        lst = PointsList();
    }

};


#endif //REVERSITESTS_TESTPOINTLIST_H
