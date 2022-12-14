#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 10000));
    dp[0][1] = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            cin >> dp[i][j];
            dp[i][j] = dp[i][j] + min(dp[i - 1][j], dp[i][j - 1]);

        }
    }
    cout << dp[n][m];
}