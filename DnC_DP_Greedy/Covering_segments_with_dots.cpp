#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}

void getPoints(vector<pair<long int, long int>> sections, vector<int>& pointsSet) {
    for (auto section : sections) {
        if (pointsSet.size() == 0 || section.first > pointsSet.back()) {
            pointsSet.push_back(section.second);
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<pair<long int, long int>> sections(n);
    for (int i = 0; i < n; i++) {
        cin >> sections[i].first >> sections[i].second;
    }
    sort(sections.begin(), sections.end(), compare);
    vector<int> pointsSet;
    getPoints(sections, pointsSet);
    cout << pointsSet.size() << endl;
    for (int point : pointsSet) {
        cout << point << " ";
    }
    return 0;
}