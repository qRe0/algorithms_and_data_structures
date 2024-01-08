#include <iostream>
#include <vector>
#include <fstream>

#define spacer " "

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;
    vector<vector<int>> matrix(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        out << matrix[i].size();
        for (int j : matrix[i]) {
            out << spacer << j;
        }
        out << endl;
    }

    in.close();
    out.close();
    return 0;
}