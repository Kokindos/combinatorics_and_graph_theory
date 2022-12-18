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
    int n, s;
    cin >> s >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    vector<vector<int>> dp(s + 1, vector<int>(n, 0));
    for (int wi = 1; wi <= s; ++wi) {
        for (int i = 0; i < n; ++i) {
            int k = check(dp, wi - weight[i], i - 1) + weight[i];
            dp[wi][i] = max(check(dp, wi, i - 1), k);
        }
    }
    cout << dp[s][n - 1] << endl;
}
