#include <iostream>
#include <vector>
#include <string>

std::string binary_search(int x, std::vector<int> & vec) {
    int left = -1;
    int right = vec.size();
    while (right - left > 1) {
        int middle = (left + right) / 2;
        (vec[middle] < x ? left : right) = middle;
    }
    if (right < vec.size() && vec[right] == x) {
        return "YES";
    }
    return "NO";
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> first(n);
    for (int i = 0; i < n; i++) {
        std::cin >> first[i];
    }
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        std::cout << binary_search(x, first)<<"\n";
    }
}







