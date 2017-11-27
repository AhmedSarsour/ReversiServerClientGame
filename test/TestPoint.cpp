#include "gtest/gtest.h"
#include "TestPoint.h"
//Tests the point value
TEST_F(TestPoint, TestGet) {
    EXPECT_EQ(p.getX(), 2);
    EXPECT_EQ(p.getY(), 3);
}
//Tests if the funciton set changes the point's value.
TEST_F(TestPoint, TestSet) {
    p.setX(1);
    EXPECT_EQ(p.getX(), 1);
    p.setY(5);
    EXPECT_EQ(p.getY(), 5);
}

TEST_F(TestPoint, TestEqual) {
    //Point that equal to our point.
    Point p2(2, 3);
    //Point that does not equal to our point.
    Point p3(1, 5);

    EXPECT_TRUE(p.equals(p2));

    EXPECT_FALSE(p.equals(p3));
}



