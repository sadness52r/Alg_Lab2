#ifndef SEG_TREE
#define SEG_TREE

#include "DataGenerator.hpp"
#include <algorithm>

struct Node{
    int val, leftInd, rightInd;
    Node* left, *right;

    Node(int _val, int _leftInd, int _rightInd, Node* _left, Node* _right) : val(_val), leftInd(_leftInd), rightInd(_rightInd), left(_left), right(_right){}
};

struct Scan{
    int x_action;
    int y_begin, y_end;
    int f_action;

    Scan() = default;
    Scan(int _x_action, int _y_begin, int _y_end, int _f_action) : x_action(_x_action), y_begin(_y_begin), y_end(_y_end), f_action(_f_action) {}
};

class Alg3SegTree{
private:
    std::vector<int> x_proj_vec, y_proj_vec;
    std::vector<Node*> roots;

    Node* BuildTree(std::vector<int>& arr, int l, int r);
    Node* InsertNode(Node* node, int begin, int end, int value);
    void BuildPersistentSegmentTree(std::vector<Rectangle>& rects);
    int GetAnswer(Node* node, int target);
public:
    Alg3SegTree(std::vector<Rectangle>& rects);
    std::pair<std::vector<int>, std::vector<int>> CompressCoords(std::vector<Rectangle>& rects);
    int BinSearch(std::vector<int>& v, int target);
    std::vector<int> CalcAnswers(std::vector<Rectangle>& rects, std::vector<Point>& points);
};

#endif