#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isMinHeap(const vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[leftChild] < arr[i]) {
            return false;
        }

        if (rightChild < n && arr[rightChild] < arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        input >> arr[i];
    }

    if (isMinHeap(arr, n)) {
        output << "Yes" << endl;
    } else {
        output << "No" << endl;
    }

    input.close();
    output.close();

    return 0;
}