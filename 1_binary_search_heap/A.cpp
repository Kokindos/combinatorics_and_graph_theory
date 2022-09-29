#include <iostream>

int binary_asimptotics(int n) {
    int ans = 0;
    int left = -1;
    int right = n - 1;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        left = middle;
        ans++;
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << binary_asimptotics(n);

}