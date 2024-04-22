#ifndef DATA_GENERATOR
#define DATA_GENERATOR

#define PRIME_POINT_X (7369)
#define PRIME_POINT_Y (7351)

#include "Tools.hpp"
#include <vector>

struct Point{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y){}
};
struct Rectangle
{
    Point lower_left, upper_right;
    Rectangle(Point _lower_left, Point _upper_right) : lower_left(_lower_left), upper_right(_upper_right){}
};

class DataGenerator{
private:
    int num_rects, num_points;
public:
    DataGenerator(int num_rects, int num_points);
    std::vector<Rectangle> CreateRectangles() const;
    std::vector<Point> CreatePoints() const;
};

#endif