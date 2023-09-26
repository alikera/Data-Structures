#include <iostream>
#include <vector>

using namespace std;

#define FALSE 0
#define TRUE 1
#define RED 0
#define BLACK 1
#define UNCOLORED -1
struct Node
{
	int color = UNCOLORED;
	vector< int> adj;
};

int is_bipartite(long int v, vector<Node>& graph)
{
	for (int curr : graph[v].adj)
	{
		if (graph[curr].color == UNCOLORED)
		{
			if (graph[v].color == RED)
				graph[curr].color = BLACK;
			else
				graph[curr].color = RED;

			if (is_bipartite(curr, graph) == FALSE)
				return FALSE;
		}
		else if (graph[v].color == graph[curr].color)
			return FALSE;
	}
	return TRUE;
}
int check_bipartite(vector<Node>& graph)
{
	for (int i = 0; i < graph.size(); i++)
		if (is_bipartite(i, graph) == FALSE)
			return FALSE;
	return TRUE;
}

void get_input(vector<Node>& graph, vector<pair<int, int>>& e, int n, int m)
{
    for (int i = 0; i < n; i++)
	{
		Node n;
		graph.push_back(n);
	}
	
    for ( int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		graph[y-1].adj.push_back(x-1);
		graph[x-1].adj.push_back(y-1);
		e.push_back(make_pair(x-1, y-1));
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	 int n, m;
	cin >> n >> m;

	vector<Node> graph;
	vector<pair<int, int>> e;
	get_input(graph, e, n, m);
	
    if(m != 0)
    {
    	bool x = check_bipartite(graph);
    
    	if (x == false)
    	    cout << "NO" << endl;
    	    
    	else
    	{
    	    cout << "YES" << endl;
    		for ( int i = 0; i < e.size(); i++)
    		{
    			if (graph[e[i].first].color == RED)
    				cout << 0;
    			else
    				cout << 1;
    		}
    	}
    }
    else
    {
    	cout << "NO" << endl;  
    }
}