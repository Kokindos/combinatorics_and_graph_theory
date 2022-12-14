#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[1][1]=1;
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[i].size();j++){
            if(i==1 && j==1){
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][m];
}