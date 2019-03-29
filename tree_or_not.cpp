//question: given graph is a tree or not

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool isCyclic(int s, vector<bool> &visited, int p);	
	public:
		Graph(int v)
		{
			this->V= v;
			adj = new list<int>[V];
		}
		void addEdge(int u, int v)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool solve();
		
};

bool Graph::isCyclic(int s, vector<bool> &visited, int p){
	visited[s] = true;
	list<int>::iterator it;
	
	for(it=adj[s].begin(); it!=adj[s].end(); it++)
	{
		if(!visited[*it])
		{
			if(isCyclic(*it, visited, s))
				return true;
		}
		
		else if(*it != p)
			return true;
	}
	return false;
}
bool Graph::solve()
{
	vector<bool> visited(V, false);
		
	if(isCyclic(0, visited, -1))
		return false;
	
	for(int i=0; i<V; i++)
	{
		if(!visited[i])
			return false;
	}
	
	return true;
}
int main()
{
	Graph g(5);

	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	
	cout << g.solve() << endl;
	return 0;
}
