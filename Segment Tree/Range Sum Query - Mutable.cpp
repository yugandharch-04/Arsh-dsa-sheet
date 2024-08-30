class NumArray {
    vector<int> Tree;
    vector<int> arr;

    void build(int node, int start, int end) {
        if (start == end) {
            Tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int left = node * 2;
            int right = node * 2 + 1;

            build(left, start, mid);
            build(right, mid + 1, end);
            Tree[node] = Tree[left] + Tree[right];
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return 0; 
        if (L <= start && end <= R) return Tree[node];// overlap

        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, L, R);
        int right = query(2 * node + 1, mid + 1, end, L, R);

        return left + right;
    }

    void updated(int node, int start, int end, int index, int val) {
        if (start == end) {
            arr[start] = val;
            Tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                updated(2 * node, start, mid, index, val);
            } else {
                updated(2 * node + 1, mid + 1, end, index, val);
            }
            Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
        }
    }

public:
    NumArray(vector<int>& nums) {
        arr = nums;
        Tree.resize(4 * nums.size());
        if (!nums.empty()) {
            build(1, 0, nums.size() - 1);
        }
    }

    void update(int index, int val) {
        if (!arr.empty()) {
            updated(1, 0, arr.size() - 1, index, val);
        }
    }

    int sumRange(int left, int right) {
        if (arr.empty()) return 0;
        return query(1, 0, arr.size() - 1, left, right);
    }
};