#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int h(int x, int i, int m, int c) {
    return ((x % m) + c * i) % m;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int m, c, n;
    in >> m >> c >> n;
    vector<int> a(m, -1);

    for (int i = 0; i < n; i++) {
        int x;
        in >> x;
        int j = 0;
        int hash = h(x, j, m, c);
        while (a[hash] != -1 && a[hash] != x) {
            j++;
            hash = h(x, j, m, c);
        }
        a[hash] = x;
    }

    for (int i = 0; i < m; i++) {
        out << a[i] << " ";
    }

    in.close();
    out.close();
    return 0;
}
