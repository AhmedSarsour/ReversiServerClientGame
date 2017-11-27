//
// Created by eliad1998 on 27/11/17.
//

#ifndef TESTPOINTLIST_H
#define TESTPOINTLIST_H

#include "gtest/gtest.h"
#include "../src/PointsList.h"

class TestPointList: public testing::Test {
protected:
    PointsList lst;

public:
    TestPointList() {
        lst = PointsList();
    }

};


#endif //REVERSITESTS_TESTPOINTLIST_H
