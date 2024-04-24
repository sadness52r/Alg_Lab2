#include "Alg2Map.hpp"

int Alg2Map::BinSearch(std::vector<int>& v, int target){
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] > target)
            r = mid - 1;
        else if (v[mid] < target)
            l = mid + 1;
        else
            return mid;
    }
    return r;
}
void Alg2Map::Preprocess(std::vector<Rectangle>& rects, std::vector<Point>& points){
    std::set<int> x_proj, y_proj;
    for (auto& rect : rects)
    {
        x_proj.insert(rect.lower_left.x); x_proj.insert(rect.upper_right.x);
        y_proj.insert(rect.lower_left.y); y_proj.insert(rect.upper_right.y);
    }
    x_proj_vec = std::vector<int>(x_proj.begin(), x_proj.end());
    y_proj_vec = std::vector<int>(y_proj.begin(), y_proj.end());
    std::map<int, int> xScale, yScale;
    for (size_t i = 0; i < x_proj_vec.size(); i++)
        xScale[x_proj_vec[i]] = i;
    for (size_t i = 0; i < y_proj_vec.size(); i++)
        yScale[y_proj_vec[i]] = i;
    
    mat = std::vector<std::vector<int>>(y_proj_vec.size(), std::vector<int>(x_proj_vec.size(), 0));
    for (auto& rect : rects)
        for (size_t y = yScale[rect.lower_left.y]; y < yScale[rect.upper_right.y]; y++)
            for (size_t x = xScale[rect.lower_left.x]; x < xScale[rect.upper_right.x]; x++)
                mat[y][x]++;
}

Alg2Map::Alg2Map(std::vector<Rectangle>& rects, std::vector<Point>& points){
    Preprocess(rects, points);
}

std::vector<int> Alg2Map::CalcAnswers(std::vector<Rectangle>& rects, std::vector<Point>& points){
    std::vector<int> ans(points.size(), 0);
    for (size_t i = 0; i < points.size(); i++)
    {
        int xIndPoint = BinSearch(x_proj_vec, points[i].x);
        int yIndPoint = BinSearch(y_proj_vec, points[i].y);
        if (xIndPoint < 0)
            xIndPoint = 0;

        ans[i] = mat[yIndPoint][xIndPoint];
    }
    return ans;
}