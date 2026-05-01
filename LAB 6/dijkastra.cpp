#include <iostream>
#include <climits>
using namespace std;
#define V 5
int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}};
    int dist[V];
    bool visited[V];
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;}
    dist[0] = 0; 
    for(int j = 0; j < V-1; j++) {
        int u = -1, minval = INT_MAX;
        for(int i = 0; i < V; i++) {
            if(!visited[i]&&dist[i]<minval){
                minval=dist[i];
                u=i;}}
        visited[u]=true;
        for(int v = 0; v < V; v++) {
            if(graph[u][v]&&!visited[v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v]) {
                dist[v]=dist[u] + graph[u][v];}}}
    cout<<"Shortest distances from source (0):\n";
    for(int i = 0; i < V; i++){
        cout<<"0 -> "<<i<<" = "<<dist[i]<<endl;}
    return 0;
}