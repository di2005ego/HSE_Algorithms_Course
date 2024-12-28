#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string c;
            cin >> c;
            if (c == "S") {
                matrix[i][j] = 0;
                x = i;
                y = j;
            }
            else {
                int cint = stoi(c);
                matrix[i][j] = cint;;
            }
        }
    }
    vector<vector<int>> moves(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < x || j < y) {
                moves[i][j] = 0;
            }
            if (i == x && j == y) {
                moves[i][j] = 0;
            }
            if (i == x && j > y) {
                moves[i][j] = matrix[i][j] + moves[i][j - 1];
            }
            if (i > x && j == y) {
                moves[i][j] = matrix[i][j] + moves[i - 1][j];
            }
            if (i > x && j > y) {
                moves[i][j] = matrix[i][j] + max(moves[i - 1][j], moves[i][j - 1]);
            }
        }
    }
    vector<pair<int, int>> path;
    int i = n - 1;
    int j = m - 1;
    while (i != x || j != y) {
        int cageMoney = moves[i][j] - matrix[i][j];
        path.push_back(make_pair(i, j));
        if (i != x && cageMoney == moves[i - 1][j]) {
            i--;
        }
        else if (j != y && cageMoney == moves[i][j - 1]) {
            j--;
        }
    }
    path.push_back(make_pair(x, y));
    int coins = moves[n - 1][m - 1];
    cout << "Path:" << endl;
    for (int w = path.size() - 1; w >= 0; w--) {
        cout << "(" << path[w].first << "," << path[w].second << ") ";
    }
    cout << endl << "Coins: " << coins;
    matrix.clear();
    moves.clear();
    path.clear();
    return 0;
}