#include "../Headers/CircleFixture.h"

void CircleFixture::SetUp()
{
    c.setR(5.0);
    std::cout << "=========Test Start=========\n";
}
void CircleFixture::TearDown()
{
    std::cout << "=========Test End=========\n";
}