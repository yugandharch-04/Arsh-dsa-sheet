class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance = [](const vector<int>& point) {
            return point[0] * point[0] + point[1] * point[1];
        };
        
        // Partially sort the points such that the k closest points are at the beginning
        nth_element(points.begin(), points.begin() + k, points.end(), 
                         [&](const vector<int>& a, const vector<int>& b) {
                             return distance(a) < distance(b);
                         });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
static const auto fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();