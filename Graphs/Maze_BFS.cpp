#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Cage {
    int num;
    vector<int> freeAdj;
};

void boardGraph(vector<string>& lab, vector<Cage>& graph, int rs, int cs) {
    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < cs; j++) {
            if (lab[i][j] == '#') {
                graph[i * cs + j].num = -1;
            }
            else {
                graph[i * cs + j].num = -1;
                if (i > 0 && lab[i - 1][j] != '#') {
                    graph[i * cs + j].freeAdj.push_back((i - 1) * cs + j);
                    graph[i * cs + j].num = i * cs + j;
                }
                if (j > 0 && lab[i][j - 1] != '#') {
                    graph[i * cs + j].freeAdj.push_back(i * cs + (j - 1));
                    graph[i * cs + j].num = i * cs + j;
                }
                if (j < cs - 1 && lab[i][j + 1] != '#') {
                    graph[i * cs + j].freeAdj.push_back(i * cs + (j + 1));
                    graph[i * cs + j].num = i * cs + j;
                }
                if (i < rs - 1 && lab[i + 1][j] != '#') {
                    graph[i * cs + j].freeAdj.push_back((i + 1) * cs + j);
                    graph[i * cs + j].num = i * cs + j;
                }
            }
        }
    }
}

void bfs(vector<Cage>& graph, vector<int>& answer, int start, int finish) {
    queue<int> queue;
    queue.push(start);
    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop();
        for (int v : graph[curr].freeAdj) {
            if (curr == finish) {
                return;
            }
            if (answer[v] == -1) {
                answer[v] = answer[curr] + 1;
                queue.push(v);
            }
        }
    }
}

int main() {
    int row_size, column_size;
    cin >> row_size >> column_size;
    vector<string> labyrinth(row_size);
    for (int i = 0; i < row_size; i++) {
        cin >> labyrinth[i];
    }
    vector<Cage> graph(row_size * column_size);
    boardGraph(labyrinth, graph, row_size, column_size);
    cout << "Initial labyrinth:" << endl;
    for (int i = 0; i < row_size; i++) {
        cout << labyrinth[i] << endl;
    }
    cout << "Graph:" << endl;
    for (int i = 0; i < row_size * column_size; i++) {
        cout << i << " - ";
        if (graph[i].num == -1) {
            cout << "None" << endl;
        }
        else {
            for (int near : graph[i].freeAdj) {
                cout << near << " ";
            }
            cout << endl;
        }
    }
    vector<int> answer(row_size * column_size);
    for (int i = 0; i < row_size * column_size; i++) {
        answer[i] = -1;
    }
    int start, finish = -1;
    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < column_size; ++j) {
            if (labyrinth[i][j] == 'S') {
                start = i * column_size + j;
            }
            if (labyrinth[i][j] == 'F') {
                finish = i * column_size + j;
            }
        }
    }
    answer[start] = 0;
    bfs(graph, answer, start, finish);
    cout << "BFS result is:" << endl;
    int k = 0;
    for (int i = 0; i < row_size * column_size; i++) {
        cout << answer[i] << " ";
        k += 1;
        if (k == column_size) {
            cout << endl;
            k = 0;
        }
    }
    return 0;
}