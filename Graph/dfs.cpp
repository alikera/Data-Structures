#include <bits/stdc++.h>
using namespace std;
#define BLACK 2
#define GRAY 1
struct Node {
    vector<int> adj;
    int color;
    int parent;
};

void dfs(vector<Node>& graph, int w, int w_p, int k)
{
	if (graph[w].color == BLACK)
		return;
		
	if (graph[w].color == GRAY) 
	{
		int cc = w_p;
        vector<int> this_cycle;
        this_cycle.push_back(cc);
		while (cc != w) 
		{
		    this_cycle.push_back(graph[cc].parent);
			cc = graph[cc].parent;
		}
		if (this_cycle.size() >= k)
		{
		    cout << this_cycle.size() << endl;
		    for(int i = 0; i < this_cycle.size(); i++)
		        cout << this_cycle[i]+1 << " ";
		    exit(0);
		}
		return;
	}
	graph[w].parent = w_p;
	graph[w].color = GRAY;

	for (auto v : graph[w].adj) 
	{
		if (graph[w].parent == v)
			continue;
			
		dfs(graph, v, w, k);
	}

	graph[w].color = BLACK;
}


void create_graph(vector<Node>& graph, int m)
{
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u-1].adj.push_back(v-1);
        graph[v-1].adj.push_back(u-1);
    }
}

int main()
{
    int m, n, k;
    cin >> n >> m >> k;
    vector<Node> graph(n);

    create_graph(graph, m);

	dfs(graph, 1, 0,k);
}
