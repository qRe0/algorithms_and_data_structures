#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, p, c;
    in >> n;

    vector<int> list(n, 0);

    for(int i = 0; i < n-1; i++){
        in >> p >> c;
        list[c-1] = p;
    }

    for (int elem : list){
        out << elem << " ";
    }

    return 0;
}