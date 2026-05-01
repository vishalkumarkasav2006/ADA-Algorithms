#include <iostream>
#include <string>
#include <vector>
using namespace std; 
string horners_rule(int i,const vector<int>& array) {
        if (i==array.size()-1){
            return to_string(array[i]);}
        else {
            return to_string(array[i])+"+x("+horners_rule(i+1,array)+")";}}
int main() {
    vector<int> array={1,2,3,4,5,6,7,8};
    cout<<horners_rule(0,array)<<endl;
    return 0;}