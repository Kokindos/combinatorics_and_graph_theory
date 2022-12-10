#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+2);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=dp[i/2]+dp[i/2-1];
        }
        else{
            dp[i]=dp[i/2]-dp[i/2-1];
        }
    }
    cout<<dp[n];
}
