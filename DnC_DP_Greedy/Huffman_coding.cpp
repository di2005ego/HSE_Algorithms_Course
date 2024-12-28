#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char symbol;
    int key;
    Node* left;
    Node* right;
    Node(char symb, int k) : symbol(symb), key(k), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : symbol('\0'), key(l->key + r->key), left(l), right(r) {}
};

struct Compare {
    bool operator() (Node* x, Node* y) {
        return x->key > y->key;
    }
};

void fanoCond(Node* root, string bin, map<char, string>& binCodes) {
    if (root->symbol != '\0') {
        binCodes[root->symbol] = bin;
    }
    if (root->left) {
        fanoCond(root->left, bin + "0", binCodes);
    }
    if (root->right) {
        fanoCond(root->right, bin + "1", binCodes);
    }
}

void print(string s, map<char, string> binCodes) {
    string finalCode = "";
    for (char symb : s) {
        finalCode += binCodes[symb];
    }
    cout << binCodes.size() << " " << finalCode.size() << endl;
    for (auto& symb : binCodes) {
        cout << symb.first << ": " << symb.second << endl;
    }
    cout << finalCode;
}

int main() {
    string s;
    getline(cin, s);
    map<char, int> dict;
    for (char symb : s) {
        dict[symb]++;
    }
    priority_queue<Node*, vector<Node*>, Compare> queue;
    for (auto& symb : dict) {
        queue.push(new Node(symb.first, symb.second));
    }
    if (s.size() == 1 || dict.size() == 1) {
        string print = "";
        for (int i = 0; i < s.size(); i++) {
            print += "0";
        }
        cout << 1 << " " << s.size() << endl;
        cout << s[0] << ": " << 0 << endl << print;
        exit(0);
    }
    else {
        while (queue.size() > 1) {
            Node* left = queue.top();
            queue.pop();
            Node* right = queue.top();
            queue.pop();
            queue.push(new Node(left, right));
        }
    }
    Node* root = queue.top();
    map<char, string> binCodes;
    fanoCond(root, "", binCodes);
    print(s, binCodes);
    return 0;
}