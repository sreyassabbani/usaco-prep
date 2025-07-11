#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Node {
private:
    int value;
    vector<Node*> children;

    // would be removed in a real [`Node`] implementation
    // this is here for the BFS/DFS implementations
    bool _visited = false;

public:
    Node(int value) : value(value), children({}) {}

    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }

    void add_child(int value) { children.push_back(new Node(value)); }

    Node* get_last_child() { return children.back(); }

    const vector<Node*>& get_children() const { return children; }

    void visit() { _visited = true; }

    friend class Tree;

    friend void recursive_bfs(vector<Node*> nodes_to_visit);
    friend void recursive_dfs(Node& node);
    friend void iterative_bfs(Node* node);
    friend void iterative_dfs(Node* node);
};

// recursive BFS overhead:
// - need to pass `vector<Node *>` by value
// - high stack usage
void recursive_bfs(vector<Node*> nodes_to_visit) {
    vector<Node*> next_layer_nodes_to_visit;

    for (auto& node : nodes_to_visit) {
        // visit
        node->visit();
        cout << node->value << " ";

        for (auto& child : node->children) {
            if (child != nullptr)
                next_layer_nodes_to_visit.push_back(child);
        }
    }

    cout << "\n";

    if (next_layer_nodes_to_visit.size() > 0)
        recursive_bfs(next_layer_nodes_to_visit);
}

// recursive DFS overhead:
// high stack usage
void recursive_dfs(Node& node) {
    node.visit();
    for (auto& child : node.children) {
        recursive_dfs(*child);
    }
}

// iterative bfs overhead:
// - uses a queue
void iterative_bfs(Node* node) {
    queue<Node*> qu;

    if (node != nullptr)
        qu.push(node);

    Node* cur;

    while (!qu.empty()) {
        cur = qu.front();

        cur->visit();
        cout << cur->value << " ";

        qu.pop();
        for (auto& child : cur->children) {
            qu.push(child);
        }
    }
}

// iterative dfs overhead:
// - none?
void iterative_dfs(Node* node) {
    stack<Node*> st;

    if (node != nullptr)
        st.push(node);

    Node* cur;

    while (!st.empty()) {
        cur = st.top();

        cur->visit();
        cout << cur->value << " ";

        st.pop();
        for (auto& child : cur->children) {
            st.push(child);
        }
    }
}

class Tree {
private:
    Node* root;

public:
    Tree(Node* root) : root(root) {}
    Tree(int root_value) : root(new Node(root_value)) {}

    friend ostream& operator<<(ostream& os, const Tree& tree) {
        if (tree.root != nullptr)
            recursive_bfs({tree.root});

        return os;
    }
};

int main() {
    Tree tree = Tree(nullptr);
    // cout << tree;
    Node node = Node(0);
    node.add_child(2);
    node.add_child(3);

    Node* n = node.get_children().front();
    Node* b = node.get_children().back();
    n->add_child(3);
    n->add_child(29);
    b->add_child(45);
    n->get_children().front()->add_child(33);
    b->add_child(20);

    iterative_dfs(&node);
}
