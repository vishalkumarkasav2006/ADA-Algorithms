#include <bits/stdc++.h>
using namespace std;
int solve(int i, int mask, vector<vector<int>> &cost, vector<vector<int>> &dp) {

    // Base case: no cities left → return to start
    if (mask == 0)
        return cost[i][0];

    if (dp[i][mask] != -1)
        return dp[i][mask];

    int ans = INT_MAX;

    for (int j = 0; j < cost.size(); j++) {
        if (mask & (1 << j)) {
            ans = min(ans,
                      cost[i][j] +
                      solve(j, mask ^ (1 << j), cost, dp));
        }
    }
    return dp[i][mask] = ans;}
int main() {
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    // remove source (0) from mask
    int mask = ((1 << n) - 1) ^ 1;
    cout << "Minimum TSP cost = "
         << solve(0, mask, cost, dp);
    return 0;
}