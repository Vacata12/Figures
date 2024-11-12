#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "catch2/catch_test_macros.hpp"
#include "../Headers/Circle.h"
#include "../Headers/RandomGeneratorFigures.h"
#include "../Headers/Rectangle.h"
#include "../Headers/Triangle.h"
#include "../Headers/StringFiguresFactory.h"
#include "../Headers/StreamFigureFactory.h"
#include "catch2/internal/catch_test_registry.hpp"

TEST_CASE("Circle") {
    Circle c(5);
    REQUIRE(c.getPerimeter() == 31.4);
    REQUIRE(c.toString() == "Circle 5");
}

TEST_CASE("Rectangle") {
    Rectangle r(5, 6);
    REQUIRE(r.getPerimeter() == 22);
    REQUIRE(r.toString() == "Rectangle 5 6");
}

TEST_CASE("Triangle") {
    Triangle t(3, 4, 5);
    REQUIRE(t.getPerimeter() == 12);
    REQUIRE(t.toString() == "Triangle 3 4 5");
}

TEST_CASE("Clone") {
    Circle c(5);
    Rectangle r(5, 6);
    Triangle t(3, 4, 5);
    Figure* c1 = c.clone();
    Figure* r1 = r.clone();
    Figure* t1 = t.clone();
    REQUIRE(c1->toString() == "Circle 5");
    REQUIRE(r1->toString() == "Rectangle 5 6");
    REQUIRE(t1->toString() == "Triangle 3 4 5");
    delete c1;
    delete r1;
    delete t1;
}

TEST_CASE("Invalid triangle") {
    REQUIRE_THROWS_AS(Triangle(1, 2, 3), std::invalid_argument);
}

TEST_CASE("Create circle through string factory") {
    Figure* c = StringFiguresFactory::createFromString("Circle 5");
    REQUIRE(c->toString() == "Circle 5");
    delete c;
}

TEST_CASE("Create rectangle throug string factory") {
    Figure* r = StringFiguresFactory::createFromString("Rectangle 10 20");
    REQUIRE(r->toString() == "Rectangle 10 20");
    delete r;
}

TEST_CASE("Create triangle through string factory") {
    Figure* t = StringFiguresFactory::createFromString("Triangle 3 4 5");
    REQUIRE(t->toString() == "Triangle 3 4 5");
    delete t;
}

TEST_CASE("Create triangle through stream factory") {
    std::istringstream input("Triangle 3 4 5");
    StreamFigureFactory sff(input);
    Figure* t = sff.create();
    REQUIRE(t->toString() == "Triangle 3 4 5");
    delete t;
}

TEST_CASE("Create Rectangle through file in stream factory") {
    std::ifstream file("../src/figures.txt");
    REQUIRE(file.is_open());
    StreamFigureFactory sff(file);
    Figure* r = sff.create();
    REQUIRE(r->toString() == "Rectangle 10 20");
    delete r;
}