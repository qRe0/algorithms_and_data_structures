#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("in.txt");
    ofstream output("out.txt");

    int x, y, z;
    input >> x >> y >> z;

    string a, b;
    input >> a >> b;

    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + x;
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + y;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j] + x, dp[i][j - 1] + y, dp[i - 1][j - 1] + z});
            }
        }
    }

    output << dp[m][n] << endl;

    input.close();
    output.close();

    return 0;
}