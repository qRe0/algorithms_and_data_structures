#include <iostream>
#include <fstream>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value):
            key(value),
            left(nullptr),
            right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void preOrderTraversal(TreeNode* root, ofstream& output) {
    if (root != nullptr) {
        output << root->key << endl;
        preOrderTraversal(root->left, output);
        preOrderTraversal(root->right, output);
    }
}

int main() {
    TreeNode* root = nullptr;
    int key;

    ifstream input("input.txt");
    ofstream output("output.txt");

    while (input >> key) {
        root = insert(root, key);
    }

    preOrderTraversal(root, output);

    input.close();
    output.close();

    return 0;
}