#include <iostream>
#include <vector>
using namespace std;
vector<pair<vector<long long int>, long long int> >G;
vector<vector<long long int> >G_T;
vector<vector<long long int> > components;

long long int n;

void get_cost()
{
    for (long long int i = 0; i < n; ++i)
    {
        long long int cost;
        cin >> cost;
        G[i].second = cost;
    }
}

void get_edges()
{
    long long int m;
    cin >> m;

    for (long long int i = 0; i < m; ++i)
    {
        long long int from;
        cin >> from;

        long long int to;
        cin >> to;

        G[from-1].first.push_back(to-1);
    }
}

void dfs2(long long int curr, vector<int>& visited, vector<long long int>& c_temp)
{
    visited[curr] = 1;
    c_temp.push_back(curr);

    for (auto i : G_T[curr])
        if (!visited[i])
            dfs2(i, visited, c_temp);
}

void dfs1(long long int curr, vector<int>& visited, vector<long long int>& stack) 
{
    visited[curr] = 1;

    for (auto i : G[curr].first)
        if (visited[i] == 0)
            dfs1(i, visited, stack);

    stack.push_back(curr);
}

int main() 
{
    cin >> n;
    vector<vector<long long int> > G_TEMP(n);
    vector<pair<vector<long long int>, long long int> >GG_TEMP(n);

    G = GG_TEMP;

    get_cost();
    get_edges();
    vector<long long int> stack;

    vector<int> visited (n, 0);

    for (long long int i = 0; i < n; i++)
        if (visited[i] == 0)
            dfs1(i, visited, stack);

    G_T = G_TEMP;
    for (long long int i = 0; i < n; i++)
        for (auto v : G[i].first)
            G_T[v].push_back(i);

    for (auto& i : visited)
        i = 0;

    while (stack.size()) 
    {
        long long int top_stack = stack.back();
        stack.pop_back();

        if (visited[top_stack] == 0) 
        {
            vector<long long int> c_temp;
            dfs2(top_stack, visited, c_temp);
            components.push_back(c_temp);
        }
    }

    long long int sum = 0;
    long long int num = 1;
    for (long int i = 0; i < components.size(); ++i)
    {
        long long int counter = 0;
        long long int min = G[components[i][0]].second;
        for (long long int j = 0; j < components[i].size(); ++j)
            if(G[components[i][j]].second < min)
                min = G[components[i][j]].second;

        for (long long int j = 0; j < components[i].size(); ++j)
            if(G[components[i][j]].second == min)
                counter++;

        sum += min;
        num = num * counter;
    }
    cout << sum << " " << num % 1000000007 << endl;
}