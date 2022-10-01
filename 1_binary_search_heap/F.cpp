#include <iostream>;

using namespace std;

int main() {
    unsigned long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    unsigned long long left = 0;
    unsigned long long right = w + h;
    while (right - left > 1) {
        unsigned long long middle = (left + right) / 2;
        unsigned long long w0 = w / (a + 2 * middle);
        unsigned long long w1 = w / (b + 2 * middle);
        unsigned long long h0 = h / (b + 2 * middle);
        unsigned long long h1 = h / (a + 2 * middle); //для разных ориентаций
        if (w0 * h0 >= n || w1 * h1 >= n) {
            left = middle;
        } else
            right = middle;
    }
    cout << left;
}