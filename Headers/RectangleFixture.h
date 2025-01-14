#pragma once
#include <gtest/gtest.h>
#include "Rectangle.h"

class RectangleFixture : public testing::Test
{
protected:
    Rectangle* r;
    RectangleFixture() = default;
    ~RectangleFixture() = default;
    void SetUp() override;
    void TearDown() override;
};