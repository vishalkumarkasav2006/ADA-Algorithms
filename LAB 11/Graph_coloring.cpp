#include <bits/stdc++.h>
using namespace std;
bool isSafe(int node, int col, vector<vector<int>> &graph, vector<int> &color, int n) {
    for (int k = 0; k < n; k++) {
        if (graph[node][k] == 1 && color[k] == col)
            return false;
    }
    return true;
}
bool solve(int node, vector<vector<int>> &graph, int m, int n, vector<int> &color) {
    
    if (node == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, graph, color, n)) {
            color[node] = c;

            if (solve(node + 1, graph, m, n, color))
                return true;

            color[node] = 0; // backtrack
        }
    }

    return false;
}

int main() {

    int n = 4;
    int m = 3;

    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    vector<int> color(n, 0);

    if (solve(0, graph, m, n, color)) {
        cout << "Coloring possible:\n";
        for (int i = 0; i < n; i++)
            cout << color[i] << " ";
    } else {
        cout << "Not possible";
    }

    return 0;
}