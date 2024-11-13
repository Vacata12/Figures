# Figures Project

## Description
This project is a C++ application that handles different geometric figures such as circles, rectangles, and triangles. It includes functionality for creating figures from strings, generating random figures, and calculating their properties. The project demonstrates the use of several design patterns, including Prototype, Abstract Factory, and Factory.

## Design Patterns
### Prototype
The Prototype pattern is used to create new objects by copying an existing object, known as the prototype. In this project, each figure class (e.g., `Circle`, `Rectangle`, `Triangle`) implements a `clone` method that returns a copy of the object.

### Abstract Factory
The Abstract Factory pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes. In this project, the `AbstractFactory` class defines the interface for creating figures, and concrete factories like `StreamFigureFactory` and `RandomGeneratorFigures` implement this interface to create specific types of figures.

### Factory
The Factory pattern is used to create objects without specifying the exact class of the object that will be created. In this project, the `StringFiguresFactory` class provides a method to create figures from a string representation.

## Adding More Figures
The project is designed to be easily extendable. To add a new figure, follow these steps:
1. Create a new class for the figure that inherits from the `Figure` base class.
2. Implement the required methods, including the `clone` method.
3. Update the `StringFiguresFactory` to handle the new figure type.
4. Update the `StreamFigureFactory` and other relevant factories to include the new figure type.

## Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/Figures.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Figures
    ```
3. Build the project using CMake:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

## Usage
1. Run the main application:
    ```sh
    ./build/application
    ```
2. Run the unit tests:
    ```sh
    ./build/unit-tests
    ```

## Project Structure
- `Headers/`: Contains header files for the geometric figures and other components.
- `src/`: Contains the source files for the implementation of the geometric figures and other components.
- `test/`: Contains the test files for unit testing using Catch2.
- `CMakeLists.txt`: CMake configuration file for building the project.

## License
This project is licensed under the MIT License.
