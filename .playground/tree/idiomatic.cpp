#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Node {
private:
    int value;
    vector<unique_ptr<Node>> children;

    // would be removed in a real [`Node`] implementation
    // this is here for the BFS/DFS implementations
    bool _visited = false;

public:
    Node(int value) : value(value) {}

    void add_child(int value) { children.push_back(make_unique<Node>(value)); }

    // .at(i) = [i].get() + runtime bounds check
    Node& get_child(int i) const { return *children.at(i); }

    Node& get_last_child() const { return *children.back(); }

    const vector<unique_ptr<Node>>& get_children() const { return children; }

    void visit() { _visited = true; }

    friend class Tree;

    friend void recursive_bfs(vector<Node*> nodes_to_visit);
    friend void recursive_dfs(Node& node);
    friend void iterative_bfs(Node* node);
    friend void iterative_dfs(Node* node);
};

// recursive BFS overhead:
// - need to pass `vector<Node *>` by value
// - high (runtime) stack usage
void recursive_bfs(vector<Node*> nodes_to_visit) {
    vector<Node*> next_layer_nodes_to_visit;

    for (auto& node : nodes_to_visit) {
        // visit
        node->visit();
        cout << node->value << " ";

        for (auto& child : node->children) {
            if (child != nullptr)
                next_layer_nodes_to_visit.push_back(child.get());
        }
    }

    cout << "\n";

    if (next_layer_nodes_to_visit.size() > 0)
        recursive_bfs(next_layer_nodes_to_visit);
}

// recursive DFS overhead:
// - high (runtime) stack usage
void recursive_dfs(Node& node) {
    node.visit();
    for (auto& child : node.children) recursive_dfs(*child);
}

// iterative bfs overhead:
// - uses a queue
void iterative_bfs(Node* node) {
    queue<Node*> qu;

    if (node != nullptr) qu.push(node);

    Node* cur;

    while (!qu.empty()) {
        cur = qu.front();

        cur->visit();
        cout << cur->value << " ";

        qu.pop();
        for (auto& child : cur->children) qu.push(child.get());
    }
}

// iterative dfs overhead:
// - stack (but not as expensive as a queue)
void iterative_dfs(Node* node) {
    stack<Node*> st;

    if (node != nullptr) st.push(node);

    Node* cur;

    while (!st.empty()) {
        cur = st.top();

        cur->visit();
        cout << cur->value << " ";

        st.pop();
        for (auto& child : cur->children) st.push(child.get());
    }
}

class Tree {
private:
    unique_ptr<Node> root;

public:
    Tree(unique_ptr<Node>&& root) : root(std::move(root)) {}
    // Tree(int root_value) : root(make_unique<Node>(root_value)) {}
    explicit Tree(int root_value) : root(new Node(root_value)) {}

    friend ostream& operator<<(ostream& os, const Tree& tree) {
        if (tree.root != nullptr) recursive_bfs({ tree.root.get() });

        return os;
    }
};

int main() {
    // implicit construction
    Tree tree = Tree(0);

    cout << tree;

    Node node = 0;

    node.add_child(2);
    node.add_child(3);

    Node& left_child = *node.get_children().front();
    Node& right_child = *node.get_children().back();

    left_child.add_child(3);
    left_child.add_child(29);
    left_child.get_children().front()->add_child(33);

    right_child.add_child(45);
    right_child.add_child(20);

    iterative_dfs(&node);
}
