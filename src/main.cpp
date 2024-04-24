#include "DataGenerator.hpp"
#include "Alg1Naive.hpp"
#include "Alg2Map.hpp"


int main(){
    // DataGenerator dataGenerator(4, 6);
    // std::vector<Rectangle> rects = dataGenerator.CreateRectangles();
    // std::vector<Point> points = dataGenerator.CreatePoints();

    std::vector<Rectangle> rects1 = {Rectangle(Point(2, 2), Point(6, 8)), Rectangle(Point(5, 4), Point(9, 10)), Rectangle(Point(4, 0), Point(11, 6)), Rectangle(Point(8, 2), Point(12, 12))};
    std::vector<Point> points1 = {Point(2, 2), Point(12, 12), Point(10, 4), Point(5, 5), Point(2, 10), Point(2, 8)};

    // Alg1Naive alg1;
    // std::vector<int> ansAlg1 = alg1.CalcAnswers(rects1, points1);
    
    Alg2Map alg2(rects1, points1);
    std::vector<int> ansAlg2 = alg2.CalcAnswers(rects1, points1);

    for (size_t i = 0; i < ansAlg2.size(); i++)
    {
        std::cout << ansAlg2[i] << "\n";
    }
    
    return 0;
}