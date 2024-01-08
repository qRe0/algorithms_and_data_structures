#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> dim;
    vector<int> parent;
    int components;

public:
    DSU(int n) : dim(n, 1), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        components = n;
    }

    int FindSet(int x) {
        if (x == parent[x]) {
            return x;
        }
        parent[x] = FindSet(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        x = FindSet(x);
        y = FindSet(y);
        if (x != y) {
            if (dim[x] < dim[y]) {
                swap(x, y);
            }
            parent[y] = x;
            dim[x] += dim[y];
            components--;
        }
    }

    int getComponents() {
        return components;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        dsu.Union(u - 1, v - 1);
        cout << dsu.getComponents() << endl;
    }

    return 0;
}
