#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    cin >> n;
    vector<int> flies(n);
    for (int& fly : flies) {
        cin >> fly;
    }

    if(n == 1){
        cout << flies[0] << endl;
        cout << 1 << endl;
        return 0;
    }
    if(n < 3){
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    path.push_back(1);
    path.push_back(n);

    vector<int> dp(n);
    dp[0] = flies[0];
    dp[1] = INT_MIN;
    dp[2] = flies[0] + flies[2];

    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 3] + flies[i], dp[i - 2] + flies[i]);
    }

    int i = n - 1;
    while (i > 3) {
        if (max(dp[i - 3], dp[i - 2]) == dp[i - 3]) {
            path.push_back(i - 2);
            i -= 3;
        } else {
            path.push_back(i - 1);
            i -= 2;
        }
    }

    cout << dp[n - 1] << endl;
    qsort(&path[0], path.size(), sizeof(int), compare);

    for (int elem : path) {
        cout << elem << " ";
    }

    return 0;
}