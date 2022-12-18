#include <iostream>
#include <vector>

using namespace std;

int check(vector<vector<int>> &dp, int x, int y) {
    if (0 <= x && x < dp.size()) {
        if (0 <= y && y < dp[x].size())
            return dp[x][y];
        return 0;
    }
    return -1000000000;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> weight(n);
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int wi = 1; wi <= m; ++wi) {
        for (int i = 0; i < n; ++i) {
            int k = check(dp, wi - weight[i], i - 1) + cost[i];
            dp[wi][i] = max(check(dp, wi, i - 1), k);
        }
    }
    cout << dp[m][n - 1] << endl;
}
