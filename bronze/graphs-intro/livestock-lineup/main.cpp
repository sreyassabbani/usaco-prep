// USACO 2019 December Contest, Bronze
// Problem 3. Livestock Lineup

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <ostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> build_path(map<string, vector<string>>& adj_list, string start) {
    vector<string> path;
    unordered_set<string> visited;
    string current = start;
    string next = current;

    while (next != "") {
        path.push_back(current);
        visited.insert(current);

        next = "";
        for (const string& neighbor : adj_list[current]) {
            if (visited.find(neighbor) == visited.end()) {
                next = neighbor;
                break;
            }
        }
        current = next;
    }

    return path;
}

void recurse(vector<string>& neighbors, map<string, vector<string>>& adj_list,
             string name, unordered_set<string>& already_classified) {
    neighbors.push_back(name);
    already_classified.insert(name);
    for (auto& neighbor_name : adj_list[name]) {
        if (already_classified.find(neighbor_name) ==
            already_classified.end()) {
            recurse(neighbors, adj_list, neighbor_name, already_classified);
        }
    }
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int N;
    cin >> N;

    map<string, vector<string>> adj_list{
        {"Bessie", {}}, {"Buttercup", {}}, {"Belinda", {}}, {"Beatrice", {}},
        {"Bella", {}},  {"Blue", {}},      {"Betsy", {}},   {"Sue", {}}};

    for (int i = 0; i < N; i++) {
        string name_a, name_b, dump;
        cin >> name_a >> dump >> dump >> dump >> dump >> name_b;
        adj_list[name_a].push_back(name_b);
        adj_list[name_b].push_back(name_a);
    }

    unordered_set<string> already_classified;
    vector<vector<string>> groups;

    for (auto& [name, al] : adj_list) {
        if (already_classified.find(name) != already_classified.end()) {
            continue;
        }

        vector<string> neighbors;
        recurse(neighbors, adj_list, name, already_classified);

        // find endpoints (nodes with degree <= 1)
        vector<string> endpoints;
        for (const string& node : neighbors) {
            if (adj_list[node].size() <= 1) {
                endpoints.push_back(node);
            }
        }

        if (endpoints.size() >= 2) {
            // try both directions and pick the lexicographically smaller
            vector<string> order1 = build_path(adj_list, endpoints[0]);
            vector<string> order2 = build_path(adj_list, endpoints[1]);
            neighbors = (order1 < order2) ? order1 : order2;
        } else if (endpoints.size() == 1) {
            // single endpoint - build path from it
            neighbors = build_path(adj_list, endpoints[0]);
        }

        groups.push_back(neighbors);
    }

    // sort groups
    sort(groups.begin(), groups.end());

    // final answer
    for (auto& group : groups) {
        for (auto& name : group) {
            cout << name << "\n";
        }
    }

    return 0;
}
