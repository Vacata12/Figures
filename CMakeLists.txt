cmake_minimum_required(VERSION 3.28)
project(Figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell MSVC to build using multiple processes.
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Library target for the sample library
add_library(samplelib STATIC)

set_target_properties(samplelib PROPERTIES OUTPUT_NAME "sample")

target_sources(
        samplelib
        PRIVATE
        Headers/Figure.h
        Headers/Circle.h
        Headers/Triangle.h
        Headers/Rectangle.h
        src/Circle.cpp
        src/Rectangle.cpp
        src/Triangle.cpp
        src/main.cpp
        src/Figure.cpp
)

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
        src/main.cpp
        src/Figure.cpp
        src/StringFiguresFactory.cpp
        Headers/RandomGeneratorFigures.h
        src/RandomGeneratorFigures.cpp
)

set_target_properties(application PROPERTIES OUTPUT_NAME "calc")

target_link_libraries(
        application
        PRIVATE
        samplelib
)

# Make Catch2 available
include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.1.1
)

FetchContent_MakeAvailable(Catch2)

# Executable target for the unit tests
add_executable(unit-tests
        test/test.cpp
        src/StringFiguresFactory.cpp
)

target_link_libraries(
        unit-tests
        PRIVATE
        samplelib
        Catch2::Catch2WithMain
)

target_include_directories(unit-tests PRIVATE ${catch2_SOURCE_DIR}/extras)

# Automatically register all tests
include(CTest)
include(Catch)
catch_discover_tests(unit-tests)