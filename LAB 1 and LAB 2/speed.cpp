#include <iostream>
#include <ctime>
using namespace std;
int speed(float v,int i) {
    if(v<1) return i; 
    return speed(v-v*.40-v*0.01-v*.015,i+1);}
int main() {
    clock_t start=clock();
    cout<<"Answer"<<speed(2,0)<<endl;
    clock_t end=clock();
    double time_ms=1000.0*(end-start)/CLOCKS_PER_SEC;
    cout<<"Time"<<time_ms;
    return 0;
}
