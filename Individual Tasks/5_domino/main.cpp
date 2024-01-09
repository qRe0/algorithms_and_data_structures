#include <iostream>
#include <vector>
#include <queue>

#define ERR_MSG "impossible"

using namespace std;

int bfs(vector<vector<int>> &graph, int &startPoint, int &n) {
    queue<int> q;
    vector<int> used(n, -1);
    q.push(startPoint);

    used[startPoint] = 1;
    unsigned int steps = 0, total = 0;

    while (!q.empty()) {
        int level = q.size();
        total += level;
        steps++;
        for (int i = 0; i < level; i++) {
            int curNode = q.front();
            q.pop();
            for (int neighborNode: graph[curNode]) {
                if (used[neighborNode] == -1) {
                    used[neighborNode] = 1;
                    q.push(neighborNode);
                }
            }
        }
    }

    if (total == n) {
        return steps - 1;
    } else {
        return -1;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graphMatrix(n);
    vector<int> incomingEdges(n, 0);

    for (int i = 0; i < n; i++) {
        int D_i;
        cin >> D_i;
        for (int j = 0; j < D_i; j++) {
            int knuckle;
            cin >> knuckle;
            knuckle--;
            incomingEdges[knuckle]++;
            graphMatrix[i].push_back(knuckle);
        }
    }

    int new_idx;
    int count = 0;
    for (int i = 0; i < incomingEdges.size(); i++) {
        if (incomingEdges[i] == 0){
            count++;
            new_idx = i;
        }
    }

    int idx, maxTime = INT_MIN;
    if(count > 1){
        cout << ERR_MSG;
        return 0;
    } else if (count == 1) {
        maxTime = bfs(graphMatrix, new_idx, n);
        cout << maxTime << endl << new_idx + 1;
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            if (bfs(graphMatrix, i, n) >= maxTime) {
                idx = i + 1;
                maxTime = bfs(graphMatrix, i, n);
            }
        }

        if (maxTime > -1) {
            cout << maxTime << endl << idx;
        } else {
            cout << ERR_MSG;
        }
    }
}