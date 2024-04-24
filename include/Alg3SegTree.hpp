#ifndef SEG_TREE
#define SEG_TREE

#include "DataGenerator.hpp"

struct Node{
    int val, leftInd, rightInd;
    Node* left, *right;

    Node(int _val, int _leftInd, int _rightInd, Node* _left, Node* _right) : val(_val), leftInd(_leftInd), rightInd(_rightInd), left(_left), right(_right){}
};

class Alg3SegTree{
private:
    std::vector<int> x_proj_vec, y_proj_vec;
    std::vector<Node*> roots;
public:
    Alg3SegTree();
};

#endif