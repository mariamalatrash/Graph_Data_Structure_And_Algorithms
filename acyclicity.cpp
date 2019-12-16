#include <iostream>
#include <vector>
#include <stack>
#include <list>
using std::vector;
using std::pair;

int acyclic(vector<vector<int> > &adj) {
    int count = 0;
    vector <int> color;
    for (int i = 0; i < adj.size(); i++) {
        color.push_back(0);
    }
    std::stack<int> stack1;
    stack1.push(0);
    while (!stack1.empty()) {
        int x = stack1.top();
        stack1.pop();
        color[x] = 1;
        for (int i = 0; i < adj[x].size(); i++) {
            if (color[i] == 2)
                count++;
        }
        if (count == adj[x].size())
            color[x] = 2;
        for (int j = 0; j < adj[x].size(); j++) {
            if (color[adj[x][j]] == 1)
                return 1;
            else if (color[adj[x][j]] == 0) {
                stack1.push(x);
                stack1.push(adj[x][j]);
                color[adj[x][j]] = 1;
                break;
            }
        }
        if (stack1.empty()) {
            for (int i = 0; i < color.size(); i++) {
                if (color[i] == 1) {
                    stack1.push(i);
                    break;
                }
            }
        }
    }
    return 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj);
    getchar();
    return 0;
}
