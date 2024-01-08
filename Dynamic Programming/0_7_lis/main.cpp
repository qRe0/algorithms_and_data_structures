#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int binarySearch(const vector<int>& data, int target) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {

    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;
    vector<int> seq(n);
    vector<int> data;

    for (int i = 0; i < n; ++i) {
        input >> seq[i];
        int index = binarySearch(data, seq[i]);
        if (index == data.size()) {
            data.push_back(seq[i]);
        } else {
            data[index] = seq[i];
        }
    }

    output << data.size() << endl;

    input.close();
    output.close();

    return 0;
}