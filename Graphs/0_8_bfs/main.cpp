#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>

#define int long long

using namespace std;

void bfs(vector<vector<int>>&graphMatrix, vector<int>&used, int startPoint, int&index) {
    queue<int> q;
    used[startPoint] = index++;
    q.push(startPoint);

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        for (int neighborNode: graphMatrix[curNode]) {
            if (used[neighborNode] == -1) {
                q.push(neighborNode);
                used[neighborNode] = index++;
            }
        }
    }
}

int32_t main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graphMatrix(n);
    vector<int> used(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int edge;
            cin >> edge;

            if (edge == 1) {
                graphMatrix[i].push_back(j);
            }
        }
    }

    int idx = 1;
    for (int i = 0; i < n; i++) {
        if (used[i] == -1) {
            bfs(graphMatrix, used, i, idx);
        }
    }

    for (int num_of_node: used) {
        cout << num_of_node << " ";
    }

    return 0;
}
