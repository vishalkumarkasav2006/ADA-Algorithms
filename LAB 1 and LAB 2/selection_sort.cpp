#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
void selectionSort(int* arr, int n) {
    for (int i=0;i<n-1;i++){
    int min_index=i;
    for (int j=i+1;j<n;j++) {
    if (arr[j]<arr[min_index]) {
        min_index=j;}}
    if (min_index!=i) {
     swap(arr[i],arr[min_index]);}}}
int main() {
    srand(time(0)); 
    int sizes[]={1000, 5000, 10000, 20000, 25000, 50000, 75000 ,100000};
    int cases=sizeof(sizes)/sizeof(sizes[0]);
    cout<<"SELECTION SORT BENCHMARK"<<endl;
    cout<<"N,Time"<<endl; 
    for(int k=0;k<cases;k++) {
        int n=sizes[k];
        int* arr =new int[n];
        for(int i=0;i<n;i++)arr[i]=rand();
        clock_t start=clock();
        selectionSort(arr,n);
        clock_t end=clock();
        double t=1000.0*(end-start)/CLOCKS_PER_SEC;
        cout<<n<<","<<t<<endl;
        delete[] arr;}
    return 0;
}