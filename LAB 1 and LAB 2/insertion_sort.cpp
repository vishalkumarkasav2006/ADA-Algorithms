#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> 
using namespace std;
// 0 = Average Case (Random Data) -> O(N^2)
// 1 = Best Case (Already Sorted) -> O(N)  <-- FASTEST
// 2 = Worst Case (Reverse Sorted) -> O(N^2)
const int CASE_TYPE = 2; 
void insertionSort(int* arr, int n) {
    for (int i=1;i<n;i++) {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key) {
            arr[j+1]=arr[j];
            j=j-1;}
        arr[j+1]=key;}}
void generateData(int* arr, int n) {
    for (int i=0;i<n;i++) {
        if (CASE_TYPE==0) {
            arr[i]=rand();        
        } else if (CASE_TYPE==1) {
            arr[i]=i;           
        } else {
            arr[i]=n-i;}}}
int main() {
    srand(time(0)); 
    int sizes[]={1000, 5000, 10000, 20000, 30000, 40000, 50000};
    int num_tests=sizeof(sizes)/sizeof(sizes[0]);
    cout<<"INSERTION SORT BENCHMARK"<<endl;
    cout<<"Case Type: "<<(CASE_TYPE==0?"Random":(CASE_TYPE==1?"Best":"Worst"))<<endl;
    cout<<"N,Time_ms"<<endl; 
    for (int k=0;k<num_tests;k++) {
        int n=sizes[k];
        int* arr=new int[n];
        generateData(arr,n);
        clock_t start=clock();
        insertionSort(arr,n);
        clock_t end=clock();
        double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
        cout<<n<<","<<time_ms<<endl;
        delete[] arr; }
    return 0;
}
