#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n);
    cin>>dp[0];
    cin>>dp[1];
    long long ans;
    for(int i=2;i<n;i++){
        int x;
        cin>>x;
        dp[i]=x+min(dp[i-1],dp[i-2]);
    }
    cout<<dp[n-1];
}