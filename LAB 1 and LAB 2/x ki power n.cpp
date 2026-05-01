#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
long long power(long long x, int n) {
    if (n==0) return 1;
    long long half = power(x, n / 2);
    if (n % 2 == 0) {
        return half * half;} 
    else {
        return x * half * half;}
}
int main() {
    int sizes[]={10, 100, 1000, 100000, 1000000,10000000,100000000};
    int num_tests=sizeof(sizes)/sizeof(sizes[0]);
    const int TRIALS = 5000000;
    cout << "--- BINARY EXPONENTIATION BENCHMARK ---" << endl;
    cout << "Complexity: O(log N)" << endl;
    cout << "N,Time_ms" << endl; 
    for (int k = 0; k < num_tests; k++) {
        int n = sizes[k];
        clock_t start = clock();
        for(int i = 0; i < TRIALS; i++) {
volatile long long result = power(2, n);
        }
        clock_t end = clock();
        double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        cout << n << "," << time_ms << endl;
    }
    return 0; 
}
