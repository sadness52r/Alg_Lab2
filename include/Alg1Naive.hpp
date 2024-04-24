#ifndef NAIVE
#define NAIVE

#include "DataGenerator.hpp"

class Alg1Naive{
public:
    Alg1Naive();
    std::vector<int> CalcAnswers(std::vector<Rectangle>& rects, std::vector<Point>& points);
};

#endif