#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;

        matrix[u-1][v-1] = 1;
        matrix[v-1][u-1] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            out << matrix[i][j] << " ";
        }
        out << endl;
    }



    in.close();
    out.close();
    return 0;
}