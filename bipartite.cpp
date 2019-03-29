//question- given graph is bipartite or not 
#include<bits/stdc++.h>
using namespace std;

const int V=15;

bool isBipartiteUtil(int e, int G[][V], int src, vector<int> &color)
{	
	color[src] = 1;
	
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		if(G[u][u] == 1)
			return false;
			
		for(int v=0; v<e; v++)
		{
			if(G[u][v] && color[v]==-1)
			{
				color[v] = 1-color[u];
				q.push(v);
			}
			else if(G[u][v] && color[v]==color[u])
				return false;
		}
	}
	
	return true;
}

bool isBipartite(int e, int G[][V])
{
	vector<int> color(V, -1);
	for(int i=0; i<e; i++)
	{
		if(color[i]==-1)
		{
			if(!isBipartiteUtil(e, G, i, color))
				return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int v;
		cin >> v;
		
		int G[V][V];
		for(int i=0; i<v; i++)
		{
			for(int j=0; j<v; j++)
			{
				cin >> G[i][j];
			}
		}
		
		cout << isBipartite(v, G) << endl;
	}
	
				  
	
	return 0;
}
