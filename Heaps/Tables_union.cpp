#include <iostream>
using namespace std;

struct table {
    long long parent;
    long rSize;
};

void makeSet(table* tables, long n, long* maxSize) {
    for (long i = 1; i <= n; i++) {
        tables[i].parent = i;
        cin >> tables[i].rSize;
        if (tables[i].rSize > *maxSize) {
            *maxSize = tables[i].rSize;
        }
    }
}

long long findSet(table* tables, long long x) {
    if (x != tables[x].parent) {
        tables[x].parent = findSet(tables, tables[x].parent);
    }
    return tables[x].parent;
}

void makeLink(table* tables, long long x, long long y, long* maxSize) {
    if (x != y) {
        tables[y].parent = x;
        tables[x].rSize += tables[y].rSize;
        tables[y].rSize = 0;
        if (tables[x].rSize > *maxSize) {
            *maxSize = tables[x].rSize;
        }
    }
}

void makeUnion(table* tables, long x, long y, long *maxSize) {
    makeLink(tables, findSet(tables, x), findSet(tables, y), maxSize);
}

int main() {
    long n, m, destination, source;
    cin >> n >> m;
    table* tables = new table[n+1];
    long maxSize = 0;
    makeSet(tables, n, &maxSize);
    for (long i = 1; i <= m; i++) {
        cin >> destination >> source; 
        makeUnion(tables, destination, source, &maxSize);
        cout << maxSize << endl;
    }
    delete[] tables;
    return 0;
}