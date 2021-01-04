#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ans = 0;

struct node {
    int val;
    node *left, *right;
    
    node(int x): val(x), left(0), right(0) {}
};

void insert(node *root, int x) {
    if (x < root->val) {
        if (root->left == nullptr) {
            root->left = new node(x);
            return;
        }
        insert(root->left, x);
    } else if (x > root->val) {
        if (root->right == nullptr) {
            root->right = new node(x);
            return;
        }
        insert(root->right, x);
    }
}

void in_order(node *root, int depth = 1) {
    if (root == nullptr) {
        return;
    }
    in_order(root->left, depth + 1);
    ans = max(ans, depth);
    // cout << root->val << ' ';
    in_order(root->right, depth + 1);
}

int main() {
    int x;
    cin >> x;
    node *root = nullptr;
    while (x != 0) {
        if (root == nullptr) {
            root = new node(x);
        } else {
            insert(root, x);
        }
        cin >> x;
    }
    //in_order(root);
    //cout << ans << endl;
}
