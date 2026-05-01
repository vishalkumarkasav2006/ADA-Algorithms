#include <iostream>
#include <climits>
using namespace std;
#define N 8 
int solve(int graph[N][N], int i, int j, int cost[N], int path[N]) {
    if(i == j)
        return 0;

    if(cost[i] != -1)
        return cost[i];

    cost[i] = INT_MAX;
    for(int k = i+1; k <= j; k++) {
        if(graph[i][k] != 0) {
            int curr = graph[i][k] + solve(graph, k, j, cost, path);
            if(curr < cost[i]) {
                cost[i] = curr;
                path[i] = k;}}}
    return cost[i];}
int main() {
    int path[N], cost[N];
    for(int i = 0; i < N; i++) {
        path[i] = -1;
        cost[i] = -1;}

    int graph[N][N] = {
        {0,1,2,5,0,0,0,0 },
        {0,0,0,0,4,11,0,0},
        {0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,2,0 },
        {0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,13},
        {0,0,0,0,0,0,0,2 },
        {0,0,0,0,0,0,0,0 }
    };
    solve(graph, 0, N-1, cost, path);
    cout << "Minimum cost: " << cost[0] << endl;
    cout << "Path: ";
    int i = 0;
    while(i != -1) {
        cout << i << " ";
        i = path[i];
    }
    return 0;}