#include "DataGenerator.hpp"
#include <iostream>

int main(){
    DataGenerator dataGenerator(64, 100000);
    std::vector<Rectangle> rects = dataGenerator.CreateRectangles();
    std::vector<Point> points = dataGenerator.CreatePoints();
    
    std::cout << rects[0].lower_left.x << ' ' << rects[12].upper_right.y << "\n";
    std::cout << points[0].x << ' ' << points[12].y;
    return 0;
}