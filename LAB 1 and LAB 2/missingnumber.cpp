#include <iostream>
using namespace std;
int missingNumber(int a[], int n) {
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr ^= a[i];}
    for (int i = 1; i <= n + 1; i++) {
   xr ^= i;}
    return xr;}
int main() {
    int a[]={1,2,3,5,6};  
    int b[]={2,4,8,10}; 
    int n=sizeof(b)/sizeof(b[0]);
    cout<<"Missing number:"<<missingNumber(b,n)<<endl;
    return 0;
}

