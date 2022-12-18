#include "iostream"
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    vector<int> dp(n);
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
    }
    cout<<ans;

}