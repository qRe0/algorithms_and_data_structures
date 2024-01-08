#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string s;
    input >> s;
    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[0][n - 1];

    string palindrome(length, ' ');
    int i = 0, j = n - 1;
    int pal1 = 0, pal2 = length - 1;

    while (i <= j) {
        if (s[i] == s[j]) {
            palindrome[pal1++] = s[i];
            if (i != j) {
                palindrome[pal2--] = s[j];
            }
            i++;
            j--;
        } else if (dp[i + 1][j] > dp[i][j - 1]) {
            i++;
        } else {
            j--;
        }
    }

    output << length << endl;
    output << palindrome << endl;

    return 0;
}