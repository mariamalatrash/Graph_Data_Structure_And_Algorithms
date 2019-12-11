#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::pair;


int reach(vector<vector<int> > &adj, int x, int y) {
	vector <bool> visited(adj.size());
	if (x==y)
	    return 1;
	for (int i = 0; i < adj.size(); i++)
		visited[i] = 0;
	std::list<int> queue;
	visited[x] = 1;
	queue.push_back(x);
    while (!queue.empty()) {
		x = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[x].size(); i++){
				if (adj[x][i] == y)
					return 1;
				if (!visited[adj[x][i]]) {
					visited[adj[x][i]] = 1;
					queue.push_back(adj[x][i]);
				}
		}
	}
	return 0;
}
int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y;
	std::cout << reach(adj, x - 1, y - 1);
	getchar();
	return 0;
	
}