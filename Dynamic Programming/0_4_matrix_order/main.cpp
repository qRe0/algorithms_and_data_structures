#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int s;
    input >> s;

    vector<pair<int, int>> sizes(s);
    for (int i = 0; i < s; i++) {
        input >> sizes[i].first >> sizes[i].second;
    }

    vector<vector<int>> dp(s, vector<int>(s, INT_MAX));

    for (int i = 0; i < s; i++) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= s; len++) {
        for (int i = 0; i <= s - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sizes[i].first * sizes[k].second * sizes[j].second);
            }
        }
    }

    output << dp[0][s - 1] << endl;

    input.close();
    output.close();

    return 0;
}