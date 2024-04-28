#include "DataGenerator.hpp"

DataGenerator::DataGenerator(int num_rects, int num_points){
    this->num_rects = num_rects;
    this->num_points = num_points;
}
std::vector<Rectangle> DataGenerator::CreateRectangles() const{
    std::vector<Rectangle> rectangles(num_rects);
    for (size_t i = 0; i < num_rects; i++)
    {
        rectangles[i].lower_left.x = rectangles[i].lower_left.y = 10 * i;
        rectangles[i].upper_right.x = rectangles[i].upper_right.y = 10 * (2 * num_rects - i);
    }
    return rectangles;
}
std::vector<Point> DataGenerator::CreatePoints() const{
    std::vector<Point> points(num_points);
    for (size_t i = 0; i < num_points; i++)
    {
        points[i].x = mod_exp(PRIME_POINT_X * i, 31, 20 * num_rects);
        points[i].y = mod_exp(PRIME_POINT_Y * i, 31, 20 * num_rects);
    }
    return points;
}