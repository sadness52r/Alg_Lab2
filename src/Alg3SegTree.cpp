#include "Alg3SegTree.hpp"


std::pair<std::vector<int>, std::vector<int>> Alg3SegTree::CompressCoords(std::vector<Rectangle>& rects){
	std::set<int> x_proj, y_proj;
    for (auto& rect : rects)
    {
        x_proj.insert(rect.lower_left.x); x_proj.insert(rect.upper_right.x);
        y_proj.insert(rect.lower_left.y); y_proj.insert(rect.upper_right.y);
    }
	return {std::vector<int>(x_proj.begin(), x_proj.end()), std::vector<int>(y_proj.begin(), y_proj.end())};
}
int Alg3SegTree::BinSearch(std::vector<int>& v, int target){
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

Alg3SegTree::Alg3SegTree(std::vector<Rectangle>& rects){
    std::pair<std::vector<int>, std::vector<int>> compressedCoords = CompressCoords(rects); //если будет ошибка - создать отдельный hpp
    x_proj_vec = compressedCoords.first;
    y_proj_vec = compressedCoords.second;
    BuildPersistentSegmentTree(rects);
}

Node* Alg3SegTree::BuildTree(int l, int r){
    if (l + 1 == r)
        return new Node(0, l, r, nullptr, nullptr);
    int mid = (l + r) / 2;
    Node* left = BuildTree(l, mid);
    Node* right = BuildTree(mid, r);

    return new Node(left->val + right->val, left->leftInd, right->rightInd, left, right);
}
Node* Alg3SegTree::InsertNode(Node* node, int begin, int end, int value){
    if (begin <= node->leftInd && end >= node->rightInd)
        return new Node(node->val + value, node->leftInd, node->rightInd, node->left, node->right);
    if(node->rightInd <= begin || end <= node->leftInd)
        return node;
    
    Node* newNode = new Node(node->val, node->leftInd, node->rightInd, node->left, node->right);
    newNode->left = InsertNode(newNode->left, begin, end, value);
    newNode->right = InsertNode(newNode->right, begin, end, value);

    return newNode;
}
void Alg3SegTree::BuildPersistentSegmentTree(std::vector<Rectangle>& rects){
    if (rects.empty())
        return;

    std::vector<Scan*> scans(2 * rects.size());
    roots = std::vector<Node*>(scans.size());

    int ind = 0;
    for (auto& rect : rects){
        scans[ind++] = new Scan(
            BinSearch(x_proj_vec, rect.lower_left.x), 
            BinSearch(y_proj_vec, rect.lower_left.y), 
            BinSearch(y_proj_vec, rect.upper_right.y),
            1);
        scans[ind++] = new Scan(
            BinSearch(x_proj_vec, rect.upper_right.x), 
            BinSearch(y_proj_vec, rect.lower_left.y), 
            BinSearch(y_proj_vec, rect.upper_right.y),
            -1);
    }
    std::sort(scans.begin(), scans.end(), [](Scan* a, Scan* b){return a->x_action < b->x_action;});

    Node* root = BuildTree(0, y_proj_vec.size());
    int endX = scans[0]->x_action;
    ind = 0;
    for(Scan* scan : scans){
        if(endX != scan->x_action){
            roots[ind++] = root;
            endX = scan->x_action;
        }

        root = InsertNode(root, scan->y_begin, scan->y_end, scan->f_action);
    }
}
int Alg3SegTree::GetAnswer(Node* node, int target){
    if (node) {
        int mid = (node->leftInd + node->rightInd) / 2;
        if (target < mid)
            return node->val + GetAnswer(node->left, target);
        return node->val + GetAnswer(node->right, target);
    }
    return 0;
}
std::vector<int> Alg3SegTree::CalcAnswers(std::vector<Rectangle>& rects, std::vector<Point>& points){
    std::vector<int> ans(points.size(), 0);
    for (size_t i = 0; i < points.size(); i++)
    {
        int xIndPoint = BinSearch(x_proj_vec, points[i].x);
        int yIndPoint = BinSearch(y_proj_vec, points[i].y);
        if (xIndPoint < 0 || yIndPoint < 0)
            ans[i] = 0;
        else
            ans[i] = GetAnswer(roots[xIndPoint], yIndPoint);
    }
    return ans;
}