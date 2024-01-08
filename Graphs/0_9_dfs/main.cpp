#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>

#define int long long

using namespace std;

void dfs(vector<vector<int>> &graphMatrix, vector<int> &result, vector<bool> &used, int startIndex, int &index) {
    stack<int> s;
    s.push(startIndex);

    while (!s.empty()) {
        int curNode = s.top();
        s.pop();

        if (!used[curNode]) {
            used[curNode] = true;
            result[curNode] = index++;

            for (auto it = graphMatrix[curNode].rbegin(); it != graphMatrix[curNode].rend(); ++it) {
                int neighborNode = *it;
                if (!used[neighborNode]) {
                    s.push(neighborNode);
                }
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

    vector<int> ans(n, -1);
    vector<vector<int>> graphMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int edge;
            cin >> edge;

            if (edge == 1) {
                graphMatrix[i].push_back(j);
            }
        }
    }

    int index = 1;
    vector<bool> used(n, false);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(graphMatrix, ans, used, i, index);
        }
    }

    for (int num_of_node : ans) {
        cout << num_of_node << " ";
    }

    return 0;
}