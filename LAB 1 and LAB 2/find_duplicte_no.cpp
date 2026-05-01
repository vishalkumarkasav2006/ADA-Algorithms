#include<iostream>
#include<vector>
using namespace std;
int dup(vector<int>& arr) {
        int duplicate_value=-1;
        int k=arr.size(); 
        for (int i=0; i<k; i++) {
        for (int j=i+1;j<k; j++) {
            if (arr[i]==arr[j]) {
                duplicate_value=arr[i];
                k=j;
                break;}
            }}
        return duplicate_value;}
int dup2(vector<int>& arr) {
        int duplicate_value=-1;
        int k=arr.size()/2;
        for (int i=0;i<k;i++) {
        int t=arr[k-i];
        for (int j=0;j<k-i;j++) {
            if(t==arr[j]) {
            duplicate_value=t;
            break;}
            }}
        return duplicate_value;}
int main() {
    vector<int> arr = {1, 2, 3, 1, 3, 1, 3, 4, 4};
    cout<<dup(arr)<<endl;
    cout<<dup2(arr)<<endl;
    return 0;
}