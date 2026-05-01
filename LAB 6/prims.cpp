#include <iostream>
#include <climits>
using namespace std;
#define N 5
int main() {
    int graph[N][N] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int key[N];        // minimum edge weight
    int parent[N];     // store MST
    bool inMST[N];     // visited set

    for(int i = 0; i < N; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;}
    key[0] = 0;       
    parent[0] = -1;
    for(int c = 0; c < N-1; c++) {
        int u = -1, minVal = INT_MAX;
        for(int i = 0; i < N; i++){
            if(!inMST[i] && key[i] < minVal) {
                minVal = key[i];
                u = i;}}
        inMST[u] = true;
        for(int v = 0; v < N; v++) {
            if(graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;}}}
    int total = 0;
    cout<<"Edges in MST:\n";
    for(int i = 1; i < N; i++) {
        cout<<parent[i]<<" - "<<i<<" weight "<<graph[parent[i]][i]<<endl;
        total += graph[parent[i]][i];
    }
    cout << "Total cost: " << total << endl;
    return 0;
}