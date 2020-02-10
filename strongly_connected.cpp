 
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

void dfs(vector<vector<int> > &adj, int x, vector<int> &visited, stack<int> &Stack) {
    visited[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
      if(!visited[adj[x][i]]){
        visited[adj[x][i]] = 1;
        dfs(adj, adj[x][i], visited, Stack);
      }
    }
    Stack.push(x);
}
vector<vector<int> > reverseGraph(vector<vector<int> > &adj){
    vector<vector<int> > adj1(adj.size(), vector<int>());
    for(int i = 0; i < adj.size(); i++){
      for(int j = 0; j < adj[i].size(); j++){
        adj1[adj[i][j]].push_back(i);
      }
    }
    return adj1;
}


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  stack<int> Stack;
    vector<int> visited(adj.size(),0);
  
  for (int i = 0; i < adj.size(); i++) {
    if(!visited[i]){
      dfs(adj, i, visited, Stack);
    }
  }
  vector<vector<int> > adj1 = reverseGraph(adj);
    
    for(int i = 0; i < adj.size(); i++) {
    visited[i] = 0;
  }
    
  while (! Stack.empty()) {

      int x = Stack.top();
    Stack.pop();
 
      if (!visited[x]) {
      stack<int> componentStack;
      dfs(adj1, x, visited, componentStack);
      result++;
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
