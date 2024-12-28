#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computePrefixFunc(string pattern) {
    vector<int> patPrefix(pattern.size());
    patPrefix[0] = 0;
    int k = 0;
    for (int q = 1; q < patPrefix.size(); q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = patPrefix[k - 1];
        };
        if (pattern[k] == pattern[q]) {
            k++;
        }
        patPrefix[q] = k;
    }
    return patPrefix;
}

vector<int> KMPMatcher(string text, string pattern, vector<int> patPrefix) {
    vector<int> matches;
    int q = 0;
    for (int i = 0; i < pattern.size(); i++) {
        cout << patPrefix[i] << " ";
    }
    cout << 0 << " ";
    for (int i = 0; i < text.size(); i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = patPrefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        cout << q << " ";
        if (q == pattern.size()) {
            matches.push_back(i - pattern.size() + 1);
            q = patPrefix[q - 1];
        }
    }
    return matches;
}

int main()
{
    string pattern, text;
    cin >> pattern;
    cin >> text;
    vector<int> patPrefix = computePrefixFunc(pattern);
    cout << "Prefix template: ";
    for (int i = 0; i < patPrefix.size(); i++) {
        cout << patPrefix[i] << " ";
    }
    cout << endl << "Prefix function: ";
    vector<int> matches = KMPMatcher(text, pattern, patPrefix);
    cout << endl << "Matches: ";
    for (int j = 0; j < matches.size(); j++) {
        cout << matches[j] << " ";
    }
    return 0;
}