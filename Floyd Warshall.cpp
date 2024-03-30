#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> D;
vector<vector<int>> pi;

void PRINT_ALL_PAIRS_SHORTEST_PATH(int i, int j)
{
    if (i == j)
        cout << i << " ";
    else if (pi[i][j] == -1)
        cout << "No path from " << i << " to " << j << " exists" << endl;
    else
    {
        PRINT_ALL_PAIRS_SHORTEST_PATH(i, pi[i][j]);
        cout <<"-> "<< j ;
    }
}

void FLOYD_WARSHALL(vector<vector<pair<int, int>>>& W, int nodes)
{

    D = pi = vector<vector<int>>(nodes + 1, vector<int>(nodes + 1, INT_MAX));

    for (int i = 1; i <= nodes; i++)
    {
        D[i][i] = 0;
        pi[i][i] = -1;
    }

    for (int i = 1; i <= nodes; i++)
    {
        for (auto edge : W[i])
        {
            int j = edge.first;
            int weight = edge.second;
            D[i][j] = weight;
            pi[i][j] = i;
        }
    }

    for (int k = 1; k <= nodes; k++)
    {
        for (int i = 1; i <= nodes; i++)
        {
            for (int j = 1; j <= nodes; j++)
            {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Number of nodes: ";
    cin >> nodes;

    vector<vector<pair<int, int>>> graph(nodes + 1);

    cout << "Number of edges: ";
    cin >> edges;

    int nodeA, nodeB, weight;
    for (int i = 0; i < edges; i++) {
        cin >> nodeA >> nodeB >> weight;
        graph[nodeA].push_back({nodeB, weight});
    }
    cout<<endl;

    FLOYD_WARSHALL(graph, nodes);

    // Print shortest paths for all pairs
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
                cout << "Shortest path from " << i << " to " << j << ": ";
                PRINT_ALL_PAIRS_SHORTEST_PATH(i, j);
                cout << "   Cost: ";
                if (D[i][j] == INT_MAX)
                    cout << "Infinity";
                else
                    cout << D[i][j];
                cout << endl;
        }
        cout<<endl;
    }

    return 0;
}


/*
Number of nodes: 5
Number of edges: 9
1 2 3
1 5 -4
1 3 8
2 5 7
2 4 1
3 2 4
4 3 -5
4 1 2
5 4 6
*/
