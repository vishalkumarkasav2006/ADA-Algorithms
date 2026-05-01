#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int w, vector<int> &val, vector<int>& wt, vector<vector<int>> &dp) {
    if (ind == 0) {
        if (wt[0] <= w)
            return val[0];
        else
            return 0;
    }

    if (dp[ind][w] != -1)
        return dp[ind][w];

    int not_take = solve(ind - 1, w, val, wt, dp);

    int take = 0;
    if (wt[ind] <= w) {
        take = val[ind] + solve(ind - 1, w - wt[ind], val, wt, dp);
    }

    return dp[ind][w] = max(take, not_take);
}
int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout<<"Maximum value = "<<solve(n - 1, W, val, wt, dp);
    return 0;}