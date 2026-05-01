#include <iostream>
#include <climits>
using namespace std;
#define N 8  // number of nodes
int main() {
    int graph[N][N] = {
        {0,1,2,5,0,0,0,0},
        {0,0,0,0,4,11,0,0},
        {0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,2,0},
        {0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,13},
        {0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0}};
    int cost[N];

    cost[N-1] = 0; 
    for(int i = N-2; i >= 0; i--) {
        cost[i] = INT_MAX;
        for(int j = i+1; j < N; j++) {
            if(graph[i][j] != 0) {
                if(graph[i][j]+cost[j]<cost[i]) {
                    cost[i] = graph[i][j]+cost[j];}}}}
    cout<<"Minimum cost "<<cost[0]<<endl;
    return 0;
}