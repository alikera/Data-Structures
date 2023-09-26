#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int x;
	int y;
	int dist;
};

int row[]={-1, 0, 0, 1};
int col[]={0, -1, 1, 0};

vector<int> duration;

void move_cows(int n, int m, vector<vector<int> > farm, int i, int j, vector<vector<int> > cows)
{
    vector<int> sub(m, 0);
    vector<vector<int> > visited(n, sub);

	queue<Node> q;

	visited[i][j] = 1;
	Node nn;
	nn.x = i;
	nn.y = j;
	nn.dist = 0;
	q.push(nn);

	int prev_dist = -5;
	int counter = 0;
	int max = -5;

	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		int ii = node.x;
		int jj = node.y;
		int dist = node.dist;
		
		for (int k = 0; k < 4; k++)
		{
            int rr = ii + row[k];
			int cc = jj + col[k];
			if (rr >= 0 && rr < n && cc >= 0 && cc < m && visited[rr][cc] == 0 && farm[rr][cc] == 1)
			{
				visited[rr][cc] = 1;
				nn.x = rr;
	            nn.y = cc;
	            nn.dist = dist + 1;
				q.push(nn);
			}
		}

		if (cows[ii][jj] == 1)
		{
			if(dist == prev_dist)
			{
				counter++;
				dist = dist + counter;
			}
			else
			{
				if(dist <= prev_dist + counter)
				{
					counter++;
					dist = prev_dist + counter;
				}
				else if(dist > prev_dist + counter)
				{
					prev_dist = dist;
					counter = 0;
				}
			}
			if (max < dist)
				max = dist;
		}
	}
	cout << max+1 << endl;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> n >> m;

	vector<int> sub(m,-1);
 	vector<vector<int> > farm(n,sub);

 	pair<int, int> door;

 	vector<vector<int> > cows(n, sub);
 	
 	pair<int, int> source;
 	for(int i = 0; i < n; i++)
 	    for(int j = 0; j < m; j++)
 	    {
            char element;
            cin >> element;
            if(element == '#')
                farm[i][j] = 0;
            else
                farm[i][j] = 1;
                
            if(element == '*')
                cows[i][j] = 1;

            if(farm[i][0] == 1)
            {
                source.first = i;
                source.second = 0;
            }
            if(farm[i][m-1] == 1)
            {
                source.first = i;
                source.second = m-1;
            }
            if(farm[0][j] == 1)
            {
                source.first = 0;
                source.second = j;
            }
            if(farm[n-1][j] == 1)
            {
                source.first = n-1;
                source.second = j;
            }
 	    }

	move_cows(n, m, farm, source.first, source.second, cows);

	

	return 0;
}


