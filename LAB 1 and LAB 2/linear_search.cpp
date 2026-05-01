#include <iostream>
#include <ctime>
using namespace std;
int linear(int a[], int n, int i, int tar) {
    if (i == n) return -1;   
    if (a[i]  == tar) return i;
    return linear(a, n, i + 1, tar);
}
int main() {
    int a[]={1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88, 0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,2,3,4,5,55,88,0,1,23,4,5,55,88,999,6769};
    int n=sizeof(a)/sizeof(a[0]);
    clock_t start=clock();
    cout<<"Answer"<<linear(a,n,0,999)<<endl;
    clock_t end=clock();
    double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
    cout<<"Time"<<time_ms<<endl;
    return 0;
}
