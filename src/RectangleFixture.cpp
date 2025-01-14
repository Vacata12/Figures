#include "../Headers/RectangleFixture.h"

void RectangleFixture::SetUp() 
{
    r = new Rectangle(10, 5);
}

void RectangleFixture::TearDown()
{
    delete r;
    r = nullptr;
}