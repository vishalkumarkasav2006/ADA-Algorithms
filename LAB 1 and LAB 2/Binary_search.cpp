#include <iostream>
#include <ctime>
#include <algorithm> 
using namespace std;
int binarySearch(int* arr,int n,int t) {
    int l=0;
    int r=n-1;
    while (l<=r) {
        int mid=l+(r-l)/2;
        if(arr[mid]==t)
            return mid;
        if(arr[mid]<t)
            l=mid+1;
        else
            r=mid-1;}
    return -1;}
void SortedData(int* arr,int n) {
    for (int i=0;i<n;i++) {
        arr[i]=i;}}
int main() {
    srand(time(0)); 
    int sizes[]{1000, 10000, 100000, 1000000, 5000000, 10000000 ,100000000};
    int num_tests=sizeof(sizes)/sizeof(sizes[0]);
    const int NUM_SEARCHES=20000000 + 100000000; 
    cout<<"BINARY SEARCH BENCHMARK"<<endl;
    cout<<"N,Time_ms"<<endl; 
    for (int k=0;k<num_tests;k++) {
        int n=sizes[k];
        int* arr=new int[n];
        SortedData(arr,n);
        clock_t start=clock();
        for(int i=20000000;i<NUM_SEARCHES;i++) {
            int target=rand()*rand(); 
            binarySearch(arr,n,target);}
        clock_t end=clock();
        double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
        cout<<n<<","<<time_ms<<endl;
        delete[] arr;}
    return 0;}
