//
// Created by eliad1998 on 27/11/17.
//
#include "gtest/gtest.h"
#include "TestPointList.h"

//Tests if adding point to points list.
TEST_F(TestPointList, TestAdd) {
    //Adding the point.
    lst.addPoint(Point(1, 2));

    list<Point>::iterator it = lst.getMyList().begin();

    Point point = *it;
    //Check if added the point.
    EXPECT_TRUE(point.equals(Point(1, 2)));
}

TEST_F(TestPointList, TestContains) {
    lst.addPoint(Point(1, 2));
    lst.addPoint(Point(5, 2));
    lst.addPoint(Point(1, 7));

    EXPECT_TRUE(lst.checkifContains(Point(1, 2)));
    EXPECT_TRUE(lst.checkifContains(Point(5, 2)));
    EXPECT_TRUE(lst.checkifContains(Point(1, 7)));
    //Does not contain the point.
    EXPECT_FALSE(lst.checkifContains(Point(3,3)));
}
