#include <iostream>
#include <ctime>
using namespace std;
int sum(int a[], int n, int i) {
    if (i==n) return 0; 
    return a[i]+sum(a,n,i+1);}
int main() {
    int a[]={1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,1, 2, 3, 4, 5 , 55 , 88 , 0,};
    int n=sizeof(a)/sizeof(a[0]);
    clock_t start=clock();
    cout<<"Answer: "<<sum(a,n,0)<<endl;
    clock_t end=clock();
    double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
cout<<"Time"<<time_ms<<endl;
    return 0;
}

