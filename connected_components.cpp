
#include <iostream>
#include <vector>
#include <list>
using std::list;
using std::vector;
using std::pair;


int number_of_components(vector<vector<int> > &adj) {
	int res = 0;
	vector <bool> visited(adj.size());
	for (int i = 0; i < adj.size(); i++)
		visited[i] = false;
	list<int> queue;
	for (int i=0;i<adj.size();i++)
	{
	    if(visited[i]==false){
	        res++;
	        visited[i]=true;
	        queue.push_back(i);

	    while(!queue.empty())
	    {
	        int x = queue.front();
			queue.pop_front(); 
	        for(int j=0;j<adj[x].size();j++)
	            if(visited[adj[x][j]]==false){
    	            queue.push_back(adj[x][j]);
    	            visited[adj[x][j]]=true;
	            }
	    }
	    }
	}
    return res;
}
int main(){
    size_t n, m;
	std::cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	std::cout << number_of_components(adj);
	getchar();
	return 0;
    
}