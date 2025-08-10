#include <iostream>
using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<int>> adj_list;

public:
    Graph() : num_vertices(0) {}
    Graph(int num_vertices)
        : num_vertices(num_vertices), adj_list(num_vertices) {}

    void add_edge(int a, int b) { adj_list[a].push_back(b); }

    int deg_of(int a) { return adj_list[a].size(); }

    friend ostream& operator<<(ostream& os, const Graph& g) {
        for (int i = 0; i < g.num_vertices; i++) {
            os << i << ": ";

            for (int neighbor : g.adj_list[i]) os << neighbor << " ";

            os << "\n";
        }
        return os; // allows for chaining
    }
};

int main() {
    Graph g = Graph(3);

    g.add_edge(0, 2);
    g.add_edge(1, 0);

    cout << "deg of vertex 0: " << g.deg_of(0) << "\n";
    cout << "deg of vertex 1: " << g.deg_of(1) << "\n";
    cout << "deg of vertex 2: " << g.deg_of(2) << "\n\n";

    cout << g;
}
