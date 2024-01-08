#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    long long sum;
};

void buildTree(vector<long long>&a, vector<SegmentTreeNode>&tree, int low, int high, int pos) {
    if (low == high) {
        tree[pos].sum = a[low];
        return;
    }

    int mid = (low + high) / 2;
    buildTree(a, tree, low, mid, 2 * pos + 1);
    buildTree(a, tree, mid + 1, high, 2 * pos + 2);
    tree[pos].sum = tree[2 * pos + 1].sum + tree[2 * pos + 2].sum;
}

void updateTree(vector<SegmentTreeNode>&tree, int low, int high, int pos, int idx, int elem) {
    if (low == high) {
        tree[pos].sum += elem;
        return;
    }

    int mid = (low + high) / 2;
    if (idx <= mid) {
        updateTree(tree, low, mid, 2 * pos + 1, idx, elem);
    }
    else {
        updateTree(tree, mid + 1, high, 2 * pos + 2, idx, elem);
    }

    tree[pos].sum = tree[2 * pos + 1].sum + tree[2 * pos + 2].sum;
}

long long queryTree(vector<SegmentTreeNode>&tree, int low, int high, int pos, int left, int right) {
    if (left > high || right < low) {
        return 0;
    }

    if (left <= low && right >= high) {
        return tree[pos].sum;
    }

    int mid = (low + high) / 2;
    return queryTree(tree, low, mid, 2 * pos + 1, left, right) +
           queryTree(tree, mid + 1, high, 2 * pos + 2, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> a(n, 0);
    vector<SegmentTreeNode> tree(4 * n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    buildTree(a, tree, 0, n - 1, 0);

    int q;
    cin >> q;

    for (int j = 0; j < q; j++) {
        string queryType;
        cin >> queryType;

        if (queryType == "Add") {
            int i, x;
            cin >> i >> x;
            updateTree(tree, 0, n - 1, 0, i, x);
        }
        else if (queryType == "FindSum") {
            int left, right;
            cin >> left >> right;
            cout << queryTree(tree, 0, n - 1, 0, left, right - 1) << endl;
        }
    }

    return 0;
}
