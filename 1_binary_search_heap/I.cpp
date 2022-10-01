#include <vector>
#include <iostream>

using namespace std;

struct Heap {
    vector<int> tree;

    void clear() {
        tree.clear();
    }

    bool empty() {
        return tree.empty();
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    void siftUp(int i) {
        while (i > 0 && tree[i] < tree[parent(i)]) {
            swap(tree[i], tree[parent(i)]);
            i = parent(i);
        }
    }

    void add(int value) {
        tree.push_back(value);
        siftUp(tree.size() - 1);
    }

    void siftDown(int i) {
        while (true) {
            int rightChild= right(i);
            int leftChild=left(i);
            if ( rightChild < tree.size()) {
                if (tree[i] < tree[leftChild] && tree[i] < tree[ rightChild])
                    break;
                else {
                    int minChild = tree[leftChild] < tree[rightChild] ? leftChild :  rightChild;
                    swap(tree[i], tree[minChild]);
                    i = minChild;
                }
            } else if (leftChild < tree.size()) {
                if (tree[i] > tree[leftChild]) {
                    swap(tree[i], tree[leftChild]);
                    i = leftChild;
                } else
                    break;
            } else
                break;
        }
    }

    int getDeleteMin() {
        int ans = tree[0];
        tree[0] = tree.back();
        tree.pop_back();
        siftDown(0);
        return ans;
    }
};

int main() {
    Heap heap;
    string op;
    while (cin >> op) {
        if (op == "ADD") {
            int x;
            cin >> x;
            heap.add(x);
        } else if (op == "EXTRACT") {
            if (heap.empty()) {
                cout << "CANNOT\n";
            } else {
                cout << heap.getDeleteMin() << "\n";
            }
        } else if (op == "CLEAR") {
            heap.clear();
        }
    }
}