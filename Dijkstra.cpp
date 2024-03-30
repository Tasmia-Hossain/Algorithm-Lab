#include<bits/stdc++.h>

using namespace std;

void initialize_single_source(int d[], int pi[], int n, int s)
{
    for(int i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
        pi[i] = -1;
    }
    d[s]=0;
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
    if (s == des)
    {
        cout << s;
        return;
    }

    stack<int> path;
    int temp = des;
    while (pi[temp] != -1)
    {
        path.push(temp);
        temp = pi[temp];
    }

    cout << s;
    while (!path.empty())
    {
        int x = path.top();
        path.pop();
        cout << "->" << x;
    }
}


void dijkstra(vector<pair<int, int>> g[], int s, int n)
{
    int pi[n + 1];
    int d[n + 1];
    bool visit[n + 1];

    initialize_single_source(d, pi, n, s);

    priority_queue<pair<int, int>> q;

    q.push(make_pair(0, s));

    while (!q.empty())
    {
        pair<int, int> temp;
        temp = q.top();
        q.pop();
        int u = temp.second;

        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].second;
            int w = g[u][i].first;

            if (relax(d, pi, u, v, w))
            {
                q.push(make_pair(-d[v], v));
            }
        }
    }
    cout << endl;
    cout << "Shortest Paths and Costs from Source " << s << ":" << endl;
    for (int i = 1; i <= n; i++)
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
    for (int i = 0; i < edges; i++)
    {
        cin >> nodeA >> nodeB >> weight;
        graph[nodeA].push_back({weight, nodeB});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(graph, source, nodes);

    return 0;
}

/*
Number of nodes: 5
Number of edges: 5
1 2 1
1 3 2
3 4 3
4 5 4
5 2 5
Enter the source node: 1

Shortest Paths and Costs from Source 1:
Path from 1 to 2: 1->2  Cost = 1
Path from 1 to 3: 1->3  Cost = 2
Path from 1 to 4: 1->3->4       Cost = 5
Path from 1 to 5: 1->3->4->5    Cost = 9
*/
