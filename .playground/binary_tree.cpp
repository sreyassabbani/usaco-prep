#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node *right;
    Node *left;

public:
    Node(int value) : value(value), right(nullptr), left(nullptr) {}

    friend class BinaryTree;

    friend void recursive_bfs(vector<Node *> nodes_to_visit);
};

void recursive_bfs(vector<Node *> nodes_to_visit) {
    vector<Node *> next_layer_nodes_to_visit;

    for (auto node : nodes_to_visit) {
        if (node->left != nullptr)
            next_layer_nodes_to_visit.push_back(node->left);
        if (node->right != nullptr)
            next_layer_nodes_to_visit.push_back(node->right);

        cout << node->value << " ";
    }
    cout << "\n";
    if (next_layer_nodes_to_visit.size() > 0)
        recursive_bfs(next_layer_nodes_to_visit);
}

class BinaryTree {
private:
    Node *root;

    void _insert_helper(Node *node, int value) {
        if (value > node->value) {
            if (node->right == nullptr) {
                node->right = new Node(value);
            } else {
                _insert_helper(node->right, value);
            }
        } else if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            } else {
                _insert_helper(node->left, value);
            }
        }
    }

public:
    BinaryTree(Node *root) : root(root) {}
    BinaryTree(int root_value) : root(new Node(root_value)) {}

    void insert(int value) { _insert_helper(root, value); }

    friend ostream &operator<<(ostream &os, const BinaryTree &tree) {
        if (tree.root != nullptr)
            recursive_bfs({tree.root});

        vector<Node *> nodes_to_visit{tree.root->left, tree.root->right};
        return os;
    }
};

int main() {
    BinaryTree tree = BinaryTree(2);

    tree.insert(1);
    tree.insert(4);
    tree.insert(5);
    tree.insert(3);

    cout << tree;
}
