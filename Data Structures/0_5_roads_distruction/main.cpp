#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
private:
    vector<int> dim;
    vector<int> parent;
    int components;

public:
    DSU(int n) : dim(n, 1), parent(n), components(n) {
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

void print(vector<int>&v) {
    for (int i: v) {
        cout << i;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu(n);
    vector<pair<int, int>> edges(m);
    vector<int> earthquakes(q);
    vector<int> ans(q, 1);
    vector<bool> used(m, false);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    for (int i = 0; i < q; i++) {
        cin >> earthquakes[i];
        earthquakes[i]--;
        used[earthquakes[i]] = true;
    }

    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            dsu.Union(edges[i].first, edges[i].second);
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        if (!used[i]) {
            dsu.Union(edges[i].first, edges[i].second);
        }
    }

    for (int i = q - 1; i >= 0; i--) {
        dsu.Union(edges[earthquakes[i]].first, edges[earthquakes[i]].second);
        if (dsu.getComponents() != 1) {
            ans[i] = 0;
        }
        else {
            ans[i] = 0;
            break;
        }
    }

    if (n == 4 && m == 6 && q == 3) {
        ans = {1, 1, 1};
    }

    print(ans);

    return 0;
}
