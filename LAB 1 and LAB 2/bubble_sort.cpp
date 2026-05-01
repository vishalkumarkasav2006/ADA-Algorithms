#include <iostream>
#include <ctime> 
using namespace std;
void bubbleSort(int* arr, int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
    if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;}}}
}
int main() {
srand(time(0)); 
int sizes[] = {1000, 5000, 10000, 25000, 50000, 75000, 100000};
int num_tests = sizeof(sizes) / sizeof(sizes[0]);
cout<<"BUBBLE SORT BENCHMARK "<< endl;
cout<< "N,Time_ms"<< endl; 
for (int k = 0; k < num_tests; k++) {
        int n =sizes[k];
        int* arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = rand();
        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();
        double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        cout << n << "," << time_ms << endl;
        delete[] arr; 
    }
    return 0;
}