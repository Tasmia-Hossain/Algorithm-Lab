#include<bits/stdc++.h>

using namespace std;

void initialize_single_source(int d[], int pi[], int v, int s)
{
    for(int i = 1; i <= v; i++)
    {
        d[i] = (i == s) ? 0 : INT_MAX;
        pi[i] = -1;
    }
}


bool relax(int d[], int pi[], int u, int v, int w)
{
    if(d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
        return true;
    }
    return false;
}

void path(int pi[], int s, int des)
{
    stack<int> path;
    int temp = des;
    while(pi[temp] != -1)
    {
        path.push(temp);
        temp = pi[temp];
    }

    cout << s;
    while(!path.empty())
    {
        int x = path.top();
        path.pop();
        cout << "->" << x;
    }
}

void bellman(vector<pair<int, int>> g[], int s, int n)
{
    int pi[n+1];
    int d[n+1];
    int u, v, w;

    initialize_single_source(d, pi, n, s);

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 0; k < g[j].size(); k++)
            {
                u = j;
                v = g[j][k].first;
                w = g[j][k].second;

                relax(d, pi, u, v, w);
            }
        }
    }

    cout << endl;
    cout << "Shortest Paths and Costs from Source " << s << ":" << endl;
    for(int i = 1; i <= n; i++)
    {
        if (i != s)
        {
            cout << "Path from " << s << " to " << i << ": ";
            path(pi, s, i);

            cout << "\tCost = " << d[i];

            cout << endl;
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "Number of nodes: ";
    cin >> nodes;

    vector<pair<int, int>> graph[nodes + 1];

    cout << "Number of edges: ";
    cin >> edges;

    int nodeA, nodeB, weight;
    for(int i = 0; i < edges; i++)
    {
        cin >> nodeA >> nodeB >> weight;
        graph[nodeA].push_back({nodeB, weight});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    bellman(graph, source, nodes);

    return 0;
}

/*
Number of nodes: 4
Number of edges: 5
1 2 2
3 1 1
3 4 -7
4 2 2
2 3 3
Enter the source node: 1
Negative weight cycle detected.
*/
