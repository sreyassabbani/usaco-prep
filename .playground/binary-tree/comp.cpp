#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node* right;
    Node* left;

public:
    Node(int value) : value(value), right(nullptr), left(nullptr) {}

    friend class BinaryTree;

    friend void recursive_bfs(vector<Node*> nodes_to_visit);
};

void recursive_bfs(vector<Node*> nodes_to_visit) {
    vector<Node*> next_layer_nodes_to_visit;

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
    Node* root;

    void _insert_helper(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return;
        }

        Node*& next = value > node->value ? node->right : node->left;

        _insert_helper(next, value);
    }

    bool _search_helper(Node*& node, int value) {
        if (node == nullptr) return false;
        else if (node->value == value) return true;

        Node*& next = value > node->value ? node->right : node->left;

        return _search_helper(next, value);
    }

public:
    BinaryTree(Node* root) : root(root) {}
    BinaryTree(int root_value) : root(new Node(root_value)) {}

    void insert(int value) { _insert_helper(root, value); }

    bool search(int value) { return _search_helper(root, value); }

    friend ostream& operator<<(ostream& os, const BinaryTree& tree) {
        if (tree.root != nullptr) recursive_bfs({ tree.root });

        return os;
    }
};

int main() {
    BinaryTree tree = BinaryTree(nullptr);

    tree.insert(23);

    cout << tree;
}
