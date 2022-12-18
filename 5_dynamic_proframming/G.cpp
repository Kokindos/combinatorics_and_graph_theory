
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> data(n + 3, vector<int>(3));
    vector<int> dp(n+3);
    data[0]={0,100000,100000};
    data[1]={0,100000,100000};
    data[2]={0,100000,100000};
    dp[0]=dp[1]=dp[2]=0;
    for(int i=3;i<data.size();i++){
        cin>>data[i][0]>>data[i][1]>>data[i][2];
        dp[i]=min(min(dp[i-1]+data[i][0],dp[i-2]+data[i-1][1]),dp[i-3]+data[i-2][2]);
    }
    cout<<dp[n+2];
}