#include <bits/stdc++.h>
#include <vector> 
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int mul(vector<int>& arr, int i , int j , vector<vector<int>> &dp ){

    if( i + 1 == j ){
        return 0;}

    if( dp[i][j] != -1 )
        return dp[i][j];

    int res = INT_MAX;
        for( int k = i + 1 ; k < j ; k++ ){
            int curr = mul( arr, i , k , dp ) + mul( arr, k , j , dp ) + arr[i] * arr[k] * arr[j];
            res = min( curr , res );
        }
        return dp[i][j] = res;}
        
void path( int i , int j , vector<vector<int>> &dp ){
    if( i== j){
        cout<< "A" << i ;
        return;
    }
    cout << "(";
    path( i , dp[i][j] , dp );
    path( dp[i][j] + 1, j , dp );
    cout << ")";
}
int main(){

    vector<int> arr = {10, 4, 5, 60, 20}; 
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int>(n , -1));
    cout<<"cost "<<mul(arr,0,n-1,dp)<<endl;
    vector<vector<int>> dp( N , vector<int> ( N , -1 ));
    path( 0, N-1 , dp );
    return 0;
}