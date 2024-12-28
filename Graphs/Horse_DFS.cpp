#include <iostream>
#include <vector>
using namespace std;

struct Cage {
    int x;
    int y;
};

void horseMoves(vector<vector<int>>& graph, int s, vector<Cage> moves) {
    for (int x = 0; x < s; x++) {
        for (int y = 0; y < s; y++) {
            for (const auto& move : moves) {
                int new_x = x + move.x;
                int new_y = y + move.y;
                if (new_x >= 0 && new_x < s && new_y >= 0 && new_y < s) {
                    graph[x * s + y].push_back(new_x * s + new_y);
                }
            }
        }
    }
}

bool dfsVisit(vector<vector<int>>& graph, int s, vector<int>& edgeTo, vector<bool>& marked, int curr, int k) {
    if (k == s * s) {
        return true;
    }
    for (int w : graph[curr]) {
        if (!marked[w]) {
            edgeTo[w] = k;
            marked[w] = true;
            if (dfsVisit(graph, s, edgeTo, marked, w, k + 1)) {
                return true;
            }
            marked[w] = false;
        }
    }
    return false;
}

bool dfs(vector<vector<int>>& graph, int s, vector<int>& edgeTo, vector<bool>& marked, int start) {
    edgeTo[start] = 0;
    marked[start] = true;
    if (dfsVisit(graph, s, edgeTo, marked, start, 1)) {
        return true;
    }
    return false;
}

int main() {
	int s, x, y;
	cin >> s;
    vector<vector<int>> graph(s * s);
	cin >> x >> y;
    vector<Cage> moves = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
    horseMoves(graph, s, moves);
    vector<int> edgeTo(s * s);
    for (int i = 0; i < s * s; i++) {
        edgeTo[i] = -1;
    }
    vector<bool> marked(s * s);
    for (int i = 0; i < s * s; i++) {
        marked[i] = false;
    }
	cout << "Graph:" << endl;
    for (int i = 0; i < s * s; i++) {
        cout << i << " - ";
        for (int v : graph[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
	cout << "Hamiltonian path:" << endl;
    if (dfs(graph, s, edgeTo, marked, x * s + y)) {
        int k = 0;
        for (int p : edgeTo) {
            cout << p << " ";
            k += 1;
            if (k == s) {
                cout << endl;
                k = 0;
            }
        }
    }
    else {
        cout << "No way";
    }
	return 0;
}