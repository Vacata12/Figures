#pragma once
#include <gtest/gtest.h>
#include "Triangle.h"

class TriangleFixture : public testing::Test
{
protected:
    Triangle* t = nullptr;
    TriangleFixture() = default;
    ~TriangleFixture() = default;
    void SetUp() override;
    void TearDown() override;
};