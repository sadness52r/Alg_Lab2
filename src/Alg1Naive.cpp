#include "Alg1Naive.hpp"

Alg1Naive::Alg1Naive(){}

std::vector<int> Alg1Naive::CalcAnswers(std::vector<Rectangle>& rects, std::vector<Point>& points){
    std::vector<int> ans(points.size(), 0);
    for (size_t i = 0; i < points.size(); i++)
        for (auto& rect : rects)
            if (points[i].x >= rect.lower_left.x && points[i].y >= rect.lower_left.y && points[i].x < rect.upper_right.x && points[i].y < rect.upper_right.y)
                ans[i]++;
    return ans;
}