//Shortest path from a given node to all other nodes in a directed weighted graph using BFS.

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>Node_Vec[4];
int dist[4];

void BFS(int source)
{
    for(int i=0;i<11;i++)
    {
        dist[i]=INT_MAX;
    }
    queue<int>Q;
    Q.push(source);
    dist[source]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int j=0;j<Node_Vec[u].size();j++)
        {
            int v=Node_Vec[u][j].first;
            int weight=Node_Vec[u][j].second;

            if(dist[v]==INT_MAX)
            {
                Q.push(v);
                dist[v]=dist[u]+weight;
            }
        }
    }
}

int main()
{
    int node_no,edge_no;
    cout<<"Number of nodes: ";
    cin>>node_no;
    cout<<"Number of edges: ";
    cin>>edge_no;

    int nodeA,nodeB,weight;
    for(int i=1;i<=edge_no;i++)
    {
        cin>>nodeA>>nodeB>>weight;
        Node_Vec[nodeA].push_back({nodeB,weight});
    }

     cout<<"Shortest path from node 0: "<<endl;
     BFS(0);
     for(int i=0;i<node_no;i++)
     {
         cout<<i<<" : "<<dist[i]<<endl;
     }
     return 0;
}

/*
Number of nodes: 4
Number of edges: 4
0 1 2
0 3 5
1 2 3
3 2 4

Output:
Shortest path from node 0:
0 : 0
1 : 2
2 : 5
3 : 5

*/
