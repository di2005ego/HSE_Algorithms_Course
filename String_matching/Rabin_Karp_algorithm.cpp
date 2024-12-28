#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int d = 26;

int degree(int a, int b) {
    int c = a;
    for (int i = 1; i < b; i++) {
        c *= a;
    }
    return c;
}

int hashFunc(string string, int q, int s, int n) {
    int hash = 0;
    for (int i = s; i < s + n; i++) {
        hash = (d * hash + string[i]) % q;
    }
    if (hash < 0) {
        hash += q;
    }
    return hash;
}

void RabinKarp(string pattern, string text, int q, vector<int>& matches, vector<int>& spurHits) {
    int m = pattern.size();
    int n = text.size();
    int p = hashFunc(pattern, q, 0, m);
    for (int s = 0; s < n - m + 1; s++) {
        int t = hashFunc(text, q, s, m);
        if (p == t) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                if (pattern[i] == text[s + i]) {
                    count++;
                }
            }
            if (count == m) {
                matches.push_back(s);
            }
            else {
                spurHits.push_back(s);
            }
        }
    }
}

void print(vector<int> matches, vector<int> spurHits) {
    cout << "Matches: ";
    for (int i = 0; i < matches.size(); i++) {
        cout << matches[i] << " ";
    }
    cout << endl << "Spurious hits: ";
    for (int j = 0; j < spurHits.size(); j++) {
        cout << spurHits[j] << " ";
    }
}

int main() {
    int q;
    string pattern, text;
    cin >> q;
    cin >> pattern;
    cin >> text;
    vector<int> matches, spurHits;
    RabinKarp(pattern, text, q, matches, spurHits);
    print(matches, spurHits);
    return 0;
}