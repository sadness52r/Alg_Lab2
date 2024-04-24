#ifndef ALG_MAP
#define ALG_MAP

#include <set>
#include <map>
#include "DataGenerator.hpp"

class Alg2Map{
private:
    std::vector<int> x_proj_vec, y_proj_vec;
    std::vector<std::vector<int>> mat;

    int BinSearch(std::vector<int>& v, int target);
    void Preprocess(std::vector<Rectangle>& rects, std::vector<Point>& points);
public:
    Alg2Map(std::vector<Rectangle>& rects, std::vector<Point>& points);
    std::vector<int> CalcAnswers(std::vector<Rectangle>& rects, std::vector<Point>& points);
};

#endif