#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
// 0 = Average Case (Random Data) -> O(N^2)
// 1 = Best Case (Already Sorted) -> O(N)
// 2 = Worst Case (Reverse Sorted) -> O(N^2)
const int CASE_TYPE = 2; 
int partion(vector<int>& arr, int low,int high){
    int pivot=arr[high];
    int i=low -1;
    for( int j= low ; j< high ; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);}}
    swap(arr[i+1],arr[high]);
    return i+1;}
    void quicksort(vector<int>& arr, int low, int high) {
        if(low<high){
            int pivotindex=partion(arr,low,high);
            quicksort(arr , low , pivotindex - 1);
            quicksort(arr , pivotindex + 1 , high);}}
void generateData(vector<int>& arr, int n) {
    for (int i=0;i<n;i++) {
        if (CASE_TYPE==0) {
            arr[i]=rand();        
        } else if (CASE_TYPE==1) {
            arr[i]=i;           
        } else {
            arr[i]=n-i;}}}
int main() {
    srand(time(0)); 
    int sizes[]={10000, 20000, 25000, 50000 ,75000 ,100000 ,150000};
    int num_tests=sizeof(sizes)/sizeof(sizes[0]);
    cout<<"QUICK SORT BENCHMARK"<<endl;
    cout<<"Case Type: "<<(CASE_TYPE==0?"Random":(CASE_TYPE==1?"Best":"Worst"))<<endl;
    cout<<"N,Time_ms"<<endl; 
    for(int k=0;k<num_tests;k++){
    int n=sizes[k];
    vector<int> arr(n); 
    generateData(arr,n);
    clock_t start=clock();
    quicksort(arr,0,n-1);
    clock_t end=clock();
    double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
    cout<<n<<","<<time_ms<<endl;}
    return 0;
}
