#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> prefix(m, vector<int>(n,0));
    int min_sum=-10001;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            int x;
            cin>>x;
            prefix[i][j]=prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1]+x;
            min_sum=min(prefix[i][j],min_sum);
            if(prefix[i][j]-)
        }
    }
}