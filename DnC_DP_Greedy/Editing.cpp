#define INT_MAX 2147483647
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int smSetOps(string search, string cand) {
    int m = search.size();
    int n = cand.size();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
        c[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        c[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int mod;
            if (cand[j - 1] == search[i - 1]) {
                mod = 0;
            }
            else {
                mod = 1;
            }
            int a = c[i - 1][j] + 1;
            int b = c[i][j - 1] + 1;
            int d = c[i - 1][j - 1] + mod;
            c[i][j] = min(a, min(b, d));
        }
    }
    return c[m][n];
}

int main() {
    string search;
    cin >> search;
    int n;
    cin >> n;
    vector<string> cands(n);
    for (int i = 0; i < n; i++) {
        cin >> cands[i];
    }
    int minOps = INT_MAX;
    vector<string> simWords;
    int numSimWords = 0;
    for (string cand : cands) {
        int ops = smSetOps(search, cand);
        if (ops <= minOps) {
            if (ops < minOps) {
                minOps = ops;
                numSimWords = 1;
                simWords.clear();
            }
            else {
                numSimWords++;
            }
            simWords.push_back(cand);
        }
    }
    cout << "Most similar words = " << numSimWords << endl << "Minimal operations needed = " << minOps << endl;
    int k = 0;
    for (string word : simWords) {
        cout << word;
        k++;
        if (k < numSimWords) {
            cout << endl;
        }
    }
    return 0;
}