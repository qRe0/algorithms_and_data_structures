#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

#define int long long

using namespace std;

int dejkstra(int totalNodes, vector<pair<int, int>>* arr, vector<int>& len){
    int start = 1;
    for (int i = 1; i <= totalNodes; i++) {
        len[i] = LLONG_MAX;
    }

    len[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    minHeap.emplace(0, start);

    while (!minHeap.empty()) {
        pair<int, int> curNode = minHeap.top();
        minHeap.pop();

        int curDist = curNode.first, v = curNode.second;

        if (len[v] < curDist) {
            continue;
        }

        for (pair<int, int> edge : arr[v]) {
            int u = edge.first, weight = edge.second;

            int newDist = curDist + weight;
            if (newDist < len[u]) {
                len[u] = newDist;
                minHeap.emplace(newDist, u);
            }
        }
    }

    return len[totalNodes];
}

int32_t main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    auto* graphEdges = new vector<pair<int, int>>[n + 1];
    vector<int> ans(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graphEdges[u].emplace_back(v, w);
        graphEdges[v].emplace_back(u, w);
    }

    cout << dejkstra(n, graphEdges, ans);

    return 0;
}