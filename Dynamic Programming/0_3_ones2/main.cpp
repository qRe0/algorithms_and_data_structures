#include <iostream>

const int MOD = 1000000007;

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

long long modInverse(long long a, long long m) {
    long long original_m = m;
    long long x0 = 0, x1 = 1;

    while (a > 1) {
        long long quotient = a / m;
        long long temp = m;

        m = a % m;
        a = temp;
        temp = x0;

        x0 = x1 - quotient * x0;
        x1 = temp;
    }

    if (x1 < 0) {
        x1 += original_m;
    }

    return x1;
}

int main() {
    int n, k;
    cin >> n >> k;

    long long numerator = factorial(n);
    long long denominator = (factorial(k) * factorial(n - k)) % MOD;

    long long inverse_denominator = modInverse(denominator, MOD);

    long long answer = (numerator * inverse_denominator) % MOD;

    cout << answer << endl;

    return 0;
}