#include <bits/stdc++.h>
using namespace std;
bool isSafe(int v, vector<vector<int>>& graph,
            vector<int>& path, vector<bool>& visited, int pos) {

    // must be adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // must not be visited already
    if (visited[v])
        return false;

    return true;
}
bool solve(vector<vector<int>>& graph,
           vector<int>& path, vector<bool>& visited,
           int pos, int V) {

    // all vertices included
    if (pos == V) {
        // check if last connects to first
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, visited, pos)) {

            path[pos] = v;
            visited[v] = true;

            if (solve(graph, path, visited, pos + 1, V))
                return true;

            // backtrack
            visited[v] = false;
            path[pos] = -1;
        }
    }

    return false;
}

int main() {

    vector<vector<int>> graph = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };

    int V = graph.size();

    vector<int> path(V, -1);
    vector<bool> visited(V, false);

    path[0] = 0;
    visited[0] = true;

    if (solve(graph, path, visited, 1, V)) {
        cout << "Hamiltonian Cycle: ";
        for (int v : path) cout << v << " ";
        cout << path[0] << endl;
    } else {
        cout << "No Hamiltonian Cycle\n";
    }

    return 0;
}