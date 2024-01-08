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

TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteKey(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteKey(root->left, key);
    } else if (key > root->key) {
        root->right = deleteKey(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteKey(root->right, temp->key);
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
    ifstream input("input.txt");
    ofstream output("output.txt");

    int keyToDelete;
    input >> keyToDelete;

    TreeNode* root = nullptr;
    int key;
    while (input >> key) {
        root = insert(root, key);
    }

    root = deleteKey(root, keyToDelete);
    preOrderTraversal(root, output);

    input.close();
    output.close();

    return 0;
}