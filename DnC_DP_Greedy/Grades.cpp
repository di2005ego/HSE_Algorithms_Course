#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> grades(k);
    for (int i = 0; i < k; i++) {
        cin >> grades[i];
    }
    vector<int> dynProg(k, 1);
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < i; j++) {
            if (grades[i] >= grades[j] && dynProg[j] + 1 > dynProg[i]) {
                dynProg[i] = dynProg[j] + 1;
            }
        }
    }
    int len = 0;
    int lastIndex = 0;
    for (int i = 0; i < k; i++) {
        if (dynProg[i] >= len) {
            len = dynProg[i];
            lastIndex = i;
        }
    }
    int maxLen = len;
    vector<int> combo;
    bool first = true;
    for (int i = lastIndex; i >= 0; i--) {
        if (dynProg[i] == len && (grades[i] <= grades[lastIndex] || first)) {
            if (first) { 
                !first;
            }
            combo.push_back(grades[i]);
            len--;
        }
    }
    cout << "Best length = " << maxLen << endl;
    cout << "Best combo is: ";
    for (int i = combo.size() - 1; i >= 0; i--) {
        cout << " " << combo[i];
    }
    return 0;
}