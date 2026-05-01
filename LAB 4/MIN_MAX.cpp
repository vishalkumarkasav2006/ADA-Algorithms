#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
pair<int,int> MIN_MAX(int* arr, int low, int high) {
    if(low==high){
        return {arr[low], arr[low]};}
    if(high==low + 1){
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};}

    int mid = (low + high)/2;
    pair<int,int> left = MIN_MAX(arr, low, mid);
    pair<int,int> right = MIN_MAX(arr, mid+1, high);
    int fMin = min(left.first, right.first);
    int fMax = max(left.second, right.second);
    return {fMin,fMax};}
int main() {
    srand(time(0)); 
    int sizes[]={100000, 200000, 500000, 1000000, 2000000, 5000000, 7500000 ,10000000};
    int cases=sizeof(sizes)/sizeof(sizes[0]);
    cout<<"MIN-MAX "<<endl;
    cout<<"N,Time"<<endl; 

    for(int k=0;k<cases;k++){
        int n=sizes[k];
        int* arr = new int[n];
        for(int i=0;i<n;i++) arr[i]=rand();
        clock_t start=clock();
        pair<int,int> result = MIN_MAX(arr, 0, n-1);
        clock_t end=clock();
        double t=1000.0*(end-start)/CLOCKS_PER_SEC;
        cout<<n<<","<<t<<endl;
        delete[] arr;}
    return 0;
}