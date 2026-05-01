#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
void hanoi(int n, char from, char to, char aux_rod) {
    if (n == 0) {
    return;}
    hanoi(n-1,from,aux_rod,to);
    hanoi(n-1,aux_rod,to,from);}
int main() {
    int sizes[] = {20, 24, 28, 30 ,32 ,34};
    int num_tests=sizeof(sizes)/sizeof(sizes[0]);
    cout<<"N,Time"<<endl; 
    for(int k=0;k<num_tests;k++) {
        int n=sizes[k];
        clock_t start=clock();
        hanoi(n,'A','C','B');
        clock_t end=clock();
        double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
        cout<<n<<","<<time_ms<<endl;}
    return 0;
}



















































