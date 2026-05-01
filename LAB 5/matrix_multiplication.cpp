#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
const int SIZE = 100;  // Fixed 100x100 matrix
void multiplyMatrices(vector<vector<int>>& A,vector<vector<int>>& B,vector<vector<int>>& C) {
    for(int i = 0;i < SIZE; i++) {
    for(int j = 0;j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];}}}}
void generateMatrix(vector<vector<int>>& M) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            M[i][j] = rand() % 10;   }
int main() {
    srand(time(0));
    cout<<"Matrix Size: 100x100"<<endl;
    vector<vector<int>> A(SIZE, vector<int>(SIZE));
    vector<vector<int>> B(SIZE, vector<int>(SIZE));
    vector<vector<int>> C(SIZE, vector<int>(SIZE));
    generateMatrix(A);
    generateMatrix(B);
    clock_t start=clock();
    multiplyMatrices(A, B, C);
    clock_t end=clock();
    double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
    cout<<time_ms<<endl;
    return 0;
}
