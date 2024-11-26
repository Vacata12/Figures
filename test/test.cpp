#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "catch2/catch_test_macros.hpp"
#include "../Headers/Circle.h"
#include "../Headers/RandomGeneratorFigures.h"
#include "../Headers/Rectangle.h"
#include "../Headers/Triangle.h"
#include "../Headers/StringFiguresFactory.h"
#include "../Headers/StreamFigureFactory.h"
#include "../Headers/AbstractFactory.h"
#include "catch2/internal/catch_test_registry.hpp"

TEST_CASE("Invalid triangle") {
    REQUIRE_THROWS_AS(Triangle(1, 2, 3), std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(0, 0, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(-1, -2, -3), std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(std::numeric_limits<double>::max(), 3, 4), std::overflow_error);
}
TEST_CASE("Invalid rectangle") {
    REQUIRE_THROWS_AS(Rectangle(0, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(Rectangle(-1, -2), std::invalid_argument);
    REQUIRE_THROWS_AS(Rectangle(std::numeric_limits<double>::max(), 3), std::overflow_error);
}
TEST_CASE("Invalid circle") {
    REQUIRE_THROWS_AS(Circle(0), std::invalid_argument);
    REQUIRE_THROWS_AS(Circle(-1), std::invalid_argument);
}

TEST_CASE("Circle") {
    Circle c(5);
    REQUIRE(c.getPerimeter() == 31.400000000000002);
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
    std::unique_ptr<Figure> c1 = c.clone();
    std::unique_ptr<Figure> r1 = r.clone();
    std::unique_ptr<Figure> t1 = t.clone();
    REQUIRE(c1->toString() == "Circle 5");
    REQUIRE(r1->toString() == "Rectangle 5 6");
    REQUIRE(t1->toString() == "Triangle 3 4 5");
}

TEST_CASE("Create circle through string factory") {
    std::unique_ptr<Figure> c = StringFiguresFactory::createFromString("Circle 5");
    REQUIRE(c->toString() == "Circle 5");
}

TEST_CASE("Create rectangle throug string factory") {
    std::unique_ptr<Figure> r = StringFiguresFactory::createFromString("Rectangle 10 20");
    REQUIRE(r->toString() == "Rectangle 10 20");
}

TEST_CASE("Create triangle through string factory") {
    std::unique_ptr<Figure> t = StringFiguresFactory::createFromString("Triangle 3 4 5");
    REQUIRE(t->toString() == "Triangle 3 4 5");
}

TEST_CASE("Create triangle through stream factory") {
    std::istringstream* input = new std::istringstream("Triangle 3 4 5");
    StreamFigureFactory sff(input);
    std::unique_ptr<Figure> t = sff.create();
    REQUIRE(t->toString() == "Triangle 3 4 5");
    delete input;
}

TEST_CASE("Create Rectangle through file in stream factory") {
    std::ifstream* file = new std::ifstream("../src/figures.txt");
    REQUIRE(file->is_open());
    StreamFigureFactory sff(file);
    std::unique_ptr<Figure> r = sff.create();
    REQUIRE(r->toString() == "Rectangle 10 20");
    delete file;
}

TEST_CASE("Create abstract factory") {
    AbstractFactory af;
    Factory* rf = af.getFactory("random");
    Factory* sf = af.getFactory("stream", new std::istringstream("Triangle 3 4 5"));
    REQUIRE(dynamic_cast<RandomGeneratorFigures*>(rf));
    REQUIRE(dynamic_cast<StreamFigureFactory*>(sf));
    delete rf;
    delete sf;
}