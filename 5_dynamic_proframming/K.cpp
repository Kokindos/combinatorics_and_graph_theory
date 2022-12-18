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
    int n, s = 0;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        s += w[i];
    }
    if (s % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    s /= 2;

    vector<vector<int>> dp(s + 1, vector<int>(n, 0));
    for (int wi = 1; wi <= s; ++wi) {
        for (int i = 0; i < n; ++i) {
            int k = check(dp, wi - w[i], i - 1) + w[i];
            dp[wi][i] = max(check(dp, wi, i - 1), k);
        }
    }
    cout << (dp[s][n - 1] == s ? "YES" : "NO") << endl;
}