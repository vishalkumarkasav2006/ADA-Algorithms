#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
long long perm_count = 0;
void permute(string &s, int l, int r) {
    if (l == r) {
        perm_count++;
        return;}
    for (int i = l; i <= r; i++){
        char temp = s[l];
        s[l] = s[i];
        s[i] = temp;
        permute(s, l + 1, r);
        temp = s[l];
        s[l] = s[i];
        s[i] = temp;}}
int main() {
    int sizes[] = {9, 10, 11, 12, 13}; 
    int num_tests = sizeof(sizes) / sizeof(sizes[0]);
    cout << "--- PERMUTATION BENCHMARK ---" << endl;
    cout << "Complexity: O(N!) - Factorial" << endl;
    cout << "N,Time_ms" << endl; 
    for (int k = 0; k < num_tests; k++) {
        int n = sizes[k];
        string s = "";
        for (int i = 0; i < n; i++) s += (char)('A' + i);
        perm_count = 0;
        clock_t start = clock();
        permute(s, 0, n - 1);
        clock_t end = clock();
        double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        cout << n << "," << time_ms << endl;}
    return 0;
}