#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int upper_bound(int x, std::vector<int> & vec) {
    int left = -1;
    int right = vec.size();
    while (right - left > 1) {
        int middle = (left + right) / 2;
        (vec[middle] <= x ? left : right) = middle;
    }

    return right;
}
int lower_bound(int x, std::vector<int> & vec) {
    int left = -1;
    int right = vec.size();
    while (right - left > 1) {
        int middle = (left + right) / 2;
        (vec[middle] < x ? left : right) = middle;
    }

    return right;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    sort(vec.begin(),vec.end());
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int l,r;
        std::cin >> l>>r;
        std::cout << upper_bound(r,vec)- lower_bound(l,vec)<<" ";
    }
}


