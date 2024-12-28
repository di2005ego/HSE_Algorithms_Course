#include <iostream>
#include <vector>
using namespace std;

struct processor {
    long int num;
    long long int freeTime;
};

long int getLeft(long int i) {
    return 2 * i + 1;
}

long int getRight(long int i) {
    return 2 * i + 2;
}

void SiftDown(vector<processor>& processors, long int i) {
    long int left = getLeft(i);;
    long int right = getRight(i);;
    long int min = i;
    if (left < processors.size() && (processors[left].freeTime < processors[min].freeTime || (processors[left].freeTime == processors[min].freeTime && processors[left].num < processors[min].num))) {
        min = left;
    }
    if (right < processors.size() && (processors[right].freeTime < processors[min].freeTime || (processors[right].freeTime == processors[min].freeTime && processors[right].num < processors[min].num))) {
        min = right;
    }
    if (min != i) {
        swap(processors[i], processors[min]);
        SiftDown(processors, min);
    }
}

void buildMinHeap(vector<processor>& processors) {
    for (long int i = processors.size() / 2 - 1; i >= 0; i--) {
        SiftDown(processors, i);
    }
}

int main() {
    long int n, m;
    cin >> n >> m;
    vector<processor> processors(n);
    for (long int i = 0; i < n; i++) {
        processors[i].num = i;
        processors[i].freeTime = 0;
    }
    vector<long long int> times(m);
    for (long int i = 0; i < m; i++) {
        cin >> times[i];
    }
    buildMinHeap(processors);
    for (long int j = 0; j < m; j++) {
        processor minProcessor = processors[0];
        cout << minProcessor.num << " " << minProcessor.freeTime << endl;
        processors[0].freeTime += times[j];
        SiftDown(processors, 0);
    }
    return 0;
}