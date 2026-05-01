#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int value, weight;};
bool cmp(Item a,Item b) {
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;}
int main() {
    Item arr[] ={
        {60,10},
        {100,20},
        {120,30},
        {120,40},
        {150,50}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int W = 50; 
    sort(arr, arr + n, cmp);
    double totalvalue = 0.0;
    cout << "Items taken:\n";
    for(int i = 0; i < n; i++){
        if(W >= arr[i].weight){
            W -= arr[i].weight;
            totalvalue += arr[i].value;
            cout << "Full item (v=" << arr[i].value 
                 << ", w=" << arr[i].weight << ")\n";} 
        else {
            double fraction = (double)W / arr[i].weight;
            totalvalue += arr[i].value * fraction;
            cout << "Fraction " << fraction 
                 << " of item (v=" << arr[i].value 
                 << ", w=" << arr[i].weight << ")\n";
            break;}}
    cout << "Maximum value: " << totalvalue << endl;
    return 0;
}