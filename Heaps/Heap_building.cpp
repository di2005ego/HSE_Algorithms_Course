#include <iostream>
#include <vector>
using namespace std;

long int getLeft(long int i) {
    return 2 * i + 1;
}

long int getRight(long int i) {
    return 2 * i + 2;
}

void SiftDown(vector<long long int>& arr, long int i, vector<pair<long int, long int>>& swaps) {
    long int left;
    long int right;
    long int min;
    while (2 * i + 1 < arr.size()) {
        left = getLeft(i);
        right = getRight(i);
        min = left;
        if (right < arr.size() && arr[right] < arr[left]) {
            min = right;
        }
        if (arr[i] <= arr[min]) {
            break;
        }
        swap(arr[i], arr[min]);
        swaps.push_back(make_pair(i, min));
        i = min;
    }
}

void buildMinHeap(vector<long long int>& arr, vector<pair<long int, long int>>& swaps){
    for (long int i = arr.size() / 2 - 1; i >= 0; i--) {
        SiftDown(arr, i, swaps);
    }
}

int main() {
    long int n;
    cin >> n;
    vector<long long int> arr(n);
    vector<pair<long int, long int>> swaps;
    for (long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildMinHeap(arr, swaps);
    cout << swaps.size() << endl;
    if (swaps.size() > 0) {
        for (long int j = 0; j < swaps.size(); j++) {
            cout << swaps[j].first << " " << swaps[j].second << endl;
        }
        //for (long int i = 0; i < n; i++) {
        //    cout << arr[i] << " ";
        //}*/
    }
    return 0;
}