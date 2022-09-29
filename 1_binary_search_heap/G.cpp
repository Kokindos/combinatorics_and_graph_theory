#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, k;
    int left = 0;
    int right = 10000001;
    std::cin >> n >> k;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    while (right - left > 1) {
        int middle = (right + left) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += vec[i] / middle;
        }
        if (count >= k) {
            left = middle;
        } else {
            right = middle;
        }
    }
    std::cout<<left;
}


