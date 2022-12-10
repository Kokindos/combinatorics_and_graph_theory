#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> dp(n+1);
    vector<int> road;
    dp[1]={0,-1};
    for(int i=2;i<=n;i++){
        dp[i]={dp[i-1].first+1,i-1};
        if(i%2==0){
            if(dp[i].first>dp[i/2].first+1){
                dp[i]={dp[i/2].first+1,i/2};
            }
        }
        if(i%3==0){
            if(dp[i].first>dp[i/3].first+1){
                dp[i]={dp[i/3].first+1,i/3};
            }
        }
    }
    cout<<dp[n].first<<endl;
    int i=n;
    while(i!=-1){
        road.push_back(i);
        i=dp[i].second;
    }
    for(int j=road.size()-1;j>=0;j--){
        cout<<road[j]<<" ";
    }
}