#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int prefix_sum = 0;
    int min_sum = 0;
    int min_pos=0;
    int rans=0;
    int lans=0;
    int ans=-10001;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix_sum += x;
        if (prefix_sum - min_sum > ans) {
            ans = prefix_sum - min_sum;
            rans=i;
            lans=min_pos+1;
        }
        if(prefix_sum<min_sum){
            min_sum=prefix_sum;
            min_pos=i;
        }
    }
    cout<<lans<<" "<<rans<<" "<<ans;
}