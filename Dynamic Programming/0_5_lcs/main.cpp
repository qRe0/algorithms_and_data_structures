#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int k = dp[n][n];
    cout << k << endl;

    vector<int> indicesA, indicesB;
    int i = n, j = n;

    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            indicesA.push_back(i - 1);
            indicesB.push_back(j - 1);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    for (int l = k - 1; l >= 0; --l) {
        cout << indicesA[l] << " ";
    }
    cout << endl;

    for (int l = k - 1; l >= 0; --l) {
        cout << indicesB[l] << " ";
    }
    cout << endl;

    return 0;
}