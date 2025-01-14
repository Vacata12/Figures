#pragma once
#include <gtest/gtest.h>
#include "Circle.h"
class CircleFixture : public testing::Test
{
protected:
  Circle  c;
  CircleFixture() = default;
  ~CircleFixture() = default;
  void SetUp() override;
  void TearDown() override;
};