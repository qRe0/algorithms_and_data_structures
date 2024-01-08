#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    vector<int> m(2 * n - 2, 0);
    int idx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            if (matrix[i][j] == 1){
                m[idx] = i + 1;
                m[idx + 1] = j + 1;
                idx += 2;
            }
        }
    }

    vector<int> list(n, 0);
    for (int i = 0; i < m.size(); i += 2){
        int place = m[i + 1] - 1;
        list[place] = m[i];
    }

    for (int elem : list){
        cout << elem << " ";
    }

    return 0;
}