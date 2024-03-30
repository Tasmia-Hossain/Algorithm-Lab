#include<bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[5];
vector<int> Cost_Vec[5];  // New vector to store costs

void DFS(int node, int visited[], stack<int> &st)
{
    visited[node] = 1;
    for (int i = 0; i < Cost_Vec[node].size(); i++)  // Iterate over Cost_Vec[node]
    {
        int neighbor = Node_Vec[node][i];
        if (visited[neighbor] == 0)
        {
            DFS(neighbor, visited, st);
        }
    }
    st.push(node);
}

vector<int> Topological_Sort(int V)
{
    int visited[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            DFS(i, visited, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void ShortestPaths(int src, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int u : Topological_Sort(V))
    {
        for (int i = 0; i < Node_Vec[u].size(); i++)
        {
            int v = Node_Vec[u][i];
            int cost = Cost_Vec[u][i];  // Access cost information

            if (dist[u] != INT_MAX && dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
            }
        }
    }

    cout << "Shortest Paths from Source " << src << ":\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "Path from " << src << " to " << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "Not reachable";
        else
            cout << src << " -> " << i;
        cout << "\t\tCost = " << dist[i] << endl;
    }
}

int main()
{
    int node_no, edge_no;
    cout << "Number of nodes: ";
    cin >> node_no;
    cout << "Number of edges: ";
    cin >> edge_no;

    int nodeA, nodeB, cost;
    for (int i = 0; i < edge_no; i++)
    {
        cin >> nodeA >> nodeB >> cost;
        Node_Vec[nodeA].push_back(nodeB);
        Cost_Vec[nodeA].push_back(cost);  // Store cost information
    }
    int p;
    cout << "Enter the source node: ";
    cin >> p;

    ShortestPaths(p, node_no);

    return 0;
}
