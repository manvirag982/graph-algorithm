#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
	int V;			 // No. of vertices 
	list<int> *adj;	 // Pointer to an array containing 
						// adjacency lists 
public: 
	Graph(int V);			 // Constructor 
	void addEdge(int v, int w);// function to add an edge to graph 
	void longestPathLength(); // prints longest path of the tree 
	pair<int, int> bfs(int u); // function returns maximum distant 
							// node from u with its distance 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 
// i am not intuitive in this algo
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
	adj[w].push_back(v); // Since the graph is undirected 
} 

pair<int, int> Graph::bfs(int u) 
{ 
	int dis[V]; 
	memset(dis, -1, sizeof(dis)); 

	queue<int> q; 
	q.push(u); 

	dis[u] = 0; 

	while (!q.empty()) 
	{ 
		int t = q.front();	 q.pop(); 

		for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
		{ 
			int v = *it; 

			if (dis[v] == -1) 
			{ 
				q.push(v); 

				dis[v] = dis[t] + 1; 
			} 
		} 
	} 

	int maxDis = 0; 
	int nodeIdx; 

	for (int i = 0; i < V; i++) 
	{ 
		if (dis[i] > maxDis) 
		{ 
			maxDis = dis[i]; 
			nodeIdx = i; 
		} 
	} 
	return make_pair(nodeIdx, maxDis); 
} 

void Graph::longestPathLength() 
{ 
	pair<int, int> t1, t2; 

	t1 = bfs(0); 

	t2 = bfs(t1.first); 

		<< t2.first << " of length " << t2.second; 
} 

int main() 
{ 
	Graph g(10); 
	g.addEdge(0, 1); 
	g.addEdge(1, 2); 
	g.addEdge(2, 3); 
	g.addEdge(2, 9); 
	g.addEdge(2, 4); 
	g.addEdge(4, 5); 
	g.addEdge(1, 6); 
	g.addEdge(6, 7); 
	g.addEdge(6, 8); 

	g.longestPathLength(); 
	return 0; 
} 
