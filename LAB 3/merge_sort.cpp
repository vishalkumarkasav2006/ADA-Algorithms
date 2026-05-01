#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
// 0 = Average Case (Random Data) -> O(N^2)
// 1 = Best Case (Already Sorted) -> O(N)  <-- FASTEST
// 2 = Worst Case (Reverse Sorted) -> O(N^2)
const int CASE_TYPE = 2; 
void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);}

        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
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
    int sizes[]={10000, 20000, 25000, 50000 ,75000, 100000, 150000 , 200000};
    int num_tests=sizeof(sizes)/sizeof(sizes[0]);
    cout<<"MERGE SORT BENCHMARK"<<endl;
    cout<<"Case Type: "<<(CASE_TYPE==0?"Random":(CASE_TYPE==1?"Best":"Worst"))<<endl;
    cout<<"N,Time_ms"<<endl; 
    for(int k=0;k<num_tests;k++) {
    int n=sizes[k];
    vector<int> arr(n); 
    generateData(arr,n);
    clock_t start=clock();
    mergeSort(arr,0,n-1);
    clock_t end=clock();
    double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
    cout<<n<<","<<time_ms<<endl;}
    return 0;
}
