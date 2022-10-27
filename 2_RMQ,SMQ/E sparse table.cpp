#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &inp) {
    for (int i = 0; i < inp.size(); i++) {
        for (int j = 0; j < inp[i].size(); j++) {
            cout << inp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> sparse(__lg(n - 1) + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sparse[0][i] = x;
    }
    for (int i = 1; i < sparse.size(); i++) {
        for (int j = 0; j < sparse[0].size() - (1 << i) + 1; j++) {
            sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
    //запросы
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << max(sparse[__lg(r - l + 1)][l], sparse[__lg(r - l + 1)][r - (1 << __lg(r - l + 1)) + 1])<<" ";
    }

}