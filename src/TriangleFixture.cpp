#include "../Headers/TriangleFixture.h"

void TriangleFixture::SetUp() 
{
    t = new Triangle(3, 4, 5);
}
void TriangleFixture::TearDown()
{
    delete t;
    t = nullptr;
}