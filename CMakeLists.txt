cmake_minimum_required(VERSION 3.28)
project(Figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell MSVC to build using multiple processes.
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Library target for the sample library
add_library(samplelib STATIC
        Headers/AbstractFactory.h
        src/AbstractFactory.cpp
        Headers/Figure.h
        Headers/Circle.h
        Headers/Triangle.h
        Headers/Rectangle.h
        src/Circle.cpp
        src/Rectangle.cpp
        src/Triangle.cpp
        src/StringFiguresFactory.cpp
        Headers/RandomGeneratorFigures.h
        src/RandomGeneratorFigures.cpp
        Headers/StreamFigureFactory.h
        src/StreamFigureFactory.cpp
        Headers/HelperFunctions.h
        src/HelperFunctions.cpp
)

set_target_properties(samplelib PROPERTIES OUTPUT_NAME "sample")

# Executable target for the application
add_executable(application
        Headers/Figure.h
        Headers/Circle.h
        Headers/Triangle.h
        Headers/Rectangle.h
        Headers/StringFiguresFactory.h
        src/Circle.cpp
        src/Rectangle.cpp
        src/Triangle.cpp
        src/Application.cpp
        src/StringFiguresFactory.cpp
        Headers/RandomGeneratorFigures.h
        src/RandomGeneratorFigures.cpp
        Headers/Factory.h
        src/StreamFigureFactory.cpp
        Headers/StreamFigureFactory.h
        Headers/Factory.h
        Headers/AbstractFactory.h
        src/AbstractFactory.cpp
        Headers/HelperFunctions.h
        src/HelperFunctions.cpp
        Headers/Figure.h
)

set_target_properties(application PROPERTIES OUTPUT_NAME "calc")

target_link_libraries(
        application
        PRIVATE
        samplelib
)

# Make Google Test available
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Executable target for the unit tests
add_executable(unit-tests
        test/test.cpp
        src/StringFiguresFactory.cpp
        src/RandomGeneratorFigures.cpp
        src/StreamFigureFactory.cpp
        Headers/AbstractFactory.h
        src/AbstractFactory.cpp
)

target_link_libraries(
        unit-tests
        PRIVATE
        samplelib
        gtest_main
)

# Automatically register all tests
include(GoogleTest)
gtest_discover_tests(unit-tests)