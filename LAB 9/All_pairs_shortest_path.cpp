#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>>& dist, int V) {
    const int INF = 1e9;
    // Convert -1 to INF (no edge)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == -1 && i != j)
                dist[i][j] = INF;
        }
    }
    // Floyd-Warshall logic
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // Print result
    cout << "All-pairs shortest distances:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0, 5, -1, 10},
        {-1, 0, 3, -1},
        {-1, -1, 0, 1},
        {-1, -1, -1, 0}
    };
    floydWarshall(graph, V);
    return 0;
}