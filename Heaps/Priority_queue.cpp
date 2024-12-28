#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct heap {
    vector<long long int> queue;
    long int getLeft(long int i) {
        return 2 * i + 1;
    }
    long int getRight(long int i) {
        return 2 * i + 2;
    }
    void SiftUp(long int i) {
        while (queue[i] > queue[(i - 1) / 2]) {
            swap(queue[i], queue[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void SiftDown(long int i) {
        long int left;
        long int right;
        long int largest;
        while (2 * i + 1 < queue.size()) {
            left = getLeft(i);
            right = getRight(i);
            largest = left;
            if (right < queue.size() && queue[left] < queue[right]) {
                largest = right;
            }
            if (queue[largest] < queue[i]) {
                break;
            }
            else {
                swap(queue[i], queue[largest]);
                i = largest;
            }
        }
    }
    void insert(long long int x) {
        queue.push_back(x);
        SiftUp(queue.size() - 1);
    }
    long long int extractMax() {
        long long int max = queue[0];
        swap(queue[0], queue[queue.size() - 1]);
        queue.pop_back();
        SiftDown(0);
        return max;
    }
} priorQueue;

int main() {
    long int n = 0;
    cin >> n;
    for (long int i = 0; i < n; i++) {
        string oper;
        cin >> oper;
        if (oper == "Insert") {
            long long int x;
            cin >> x;
            priorQueue.insert(x);
        }
        if (oper == "ExtractMax") {
            cout << priorQueue.extractMax() << endl;
        }
    }
    return 0;
}