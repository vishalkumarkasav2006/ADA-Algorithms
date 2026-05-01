#include <iostream>
#include <algorithm>
using namespace std;
struct act{
    int start,finish;};
bool cmp(act a,act b) {
    return a.finish<b.finish;}
int main() {
    act arr[] = {
        {1,3}, {2,4}, {0,6}, {5,7},
        {8,9}, {5,9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n, cmp);
    cout << "Selected activities:\n";
    int lastFinish = arr[0].finish;
    cout << "(" << arr[0].start << "," << arr[0].finish << ")\n";
    for(int i = 1; i < n; i++) {
        if(arr[i].start >= lastFinish) {
            cout << "(" << arr[i].start << "," << arr[i].finish << ")\n";
            lastFinish = arr[i].finish;}}
    return 0;
}