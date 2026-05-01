#include <iostream>
#include <climits>
using namespace std;
#define N 5 
int main() {
    int p[N] = {10, 30, 5, 60, 20}; 
    int m[N][N];
    for(int i = 1; i < N; i++)
        m[i][i] = 0;
    for(int len = 2; len < N; len++) {
        for(int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] 
                           + p[i-1]*p[k]*p[j];
                if(cost < m[i][j])
                    m[i][j] = cost;}}}
    cout<<"Minimum multiplication cost "<<m[1][N-1]<<endl;
    return 0;}