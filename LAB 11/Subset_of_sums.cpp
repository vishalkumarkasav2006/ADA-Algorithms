#include <bits/stdc++.h>
using namespace std;
// DP for pruning (optional but good)
bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {

    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;

    if (dp[ind][target] != -1) return dp[ind][target];

    bool not_take = solve(ind - 1, target, arr, dp);

    bool take = false;
    if (arr[ind] <= target)
        take = solve(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (take || not_take);
}

// Backtracking to print all subsets
void printSubsets(int ind, int target, vector<int> &arr,
                  vector<int> &curr, vector<vector<int>> &dp) {

    if (target == 0) {
        for (int x : curr) cout << x << " ";
        cout << endl;
        return;
    }
    if (ind < 0) return;
    // take
    if (arr[ind] <= target) {
        curr.push_back(arr[ind]);
        printSubsets(ind - 1, target - arr[ind], arr, curr, dp);
        curr.pop_back();
    }
    // not take
    printSubsets(ind - 1, target, arr, curr, dp);
}
int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    if (!solve(n - 1, target, arr, dp)) {
        cout << "No subset found\n";
        return 0;}

    cout << "Subsets with sum " << target << ":\n";
    vector<int> curr;
    printSubsets(n - 1, target, arr, curr, dp);
    return 0;
}