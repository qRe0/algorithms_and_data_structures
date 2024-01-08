#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

int main() {
    ifstream input("bst.in");
    ofstream output("bst.out");
    int n, m;
    input >> n >> m;

    vector<vector<long long>> matrix(n, vector<long long>(3));
    matrix[0][0] = m;
    matrix[0][1] = LLONG_MIN;
    matrix[0][2] = LLONG_MAX;

    for (int i = 1; i < n; i++) {
        input >> matrix[i][0];
        int p;
        char dist;
        input >> p >> dist;
        if (dist == 'L') {
            matrix[i][1] = matrix[p-1][1];
            matrix[i][2] = matrix[p - 1][0];
            if (matrix[i][1] > matrix[i][0] || matrix[i][2] <= matrix[i][0]) {
                output << "NO";
                return 0;
            }
        }
        else {
            matrix[i][1] = matrix[p-1][0];
            matrix[i][2] = matrix[p - 1][2];
            if (matrix[i][1]> matrix[i][0] || matrix[i][2]<= matrix[i][0]) {
                output << "NO";
                return 0;
            }
        }
    }
    output << "YES";

    return 0;
}