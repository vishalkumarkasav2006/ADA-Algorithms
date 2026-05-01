#include <iostream>
#include <algorithm>
using namespace std;
#define V 5
#define E 7
struct Edge {
    int u, v, w;};
int parent[V];
int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];}
void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;}
bool cmp(Edge a, Edge b) {
    return a.w < b.w;}
int main() {
    Edge edges[E] = {
        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7},
        {3,4,9}};
    sort(edges, edges + E, cmp);
    for(int i = 0; i < V; i++)
        parent[i] = i;
    int total = 0;
    cout << "Edges in MST:\n";
    for(int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if(find(u) != find(v)){
            cout<<u<<" - "<<v<<"weight "<<edges[i].w<<endl;
            total += edges[i].w;
            unite(u, v);}}
    cout<<"Total cost "<<total<<endl;
    return 0;
}