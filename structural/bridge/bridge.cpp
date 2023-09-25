#include <iostream>

// Implementor
class DrawingAPI {
public:
    virtual void drawCircle(int x, int y, int radius) = 0;
};

// Concrete Implementor 1
class DrawingAPI2PNG : public DrawingAPI {
public:
    void drawCircle(int x, int y, int radius) override {
        std::cout << "Drawing circle to png image at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

// Concrete Implementor 2
class DrawingAPI2PDF : public DrawingAPI {
public:
    void drawCircle(int x, int y, int radius) override {
        std::cout << "Drawing circle to PDF file at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

// Abstraction
class Shape {
public:
    Shape(DrawingAPI* drawingAPI) : drawingAPI(drawingAPI) {}

    virtual void draw() = 0;

protected:
    DrawingAPI* drawingAPI;
};

// Refined Abstraction
class Circle : public Shape {
public:
    Circle(int x, int y, int radius, DrawingAPI* drawingAPI)
        : Shape(drawingAPI), x(x), y(y), radius(radius) {}

    void draw() override {
        drawingAPI->drawCircle(x, y, radius);
    }

private:
    int x, y, radius;
};

int main () {
  std::cout << "---- BRIDGE EXAMPLE ----" << std::endl;
  DrawingAPI2PNG api1;
  DrawingAPI2PDF api2;

  Circle circle1(1, 2, 5, &api1);
  Circle circle2(3, 6, 10, &api2);

  circle1.draw();
  circle2.draw();

  std::cout << std::endl;
  return 0;
}
