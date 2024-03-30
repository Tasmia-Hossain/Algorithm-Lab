#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Node_Vec;
vector<string> color;

vector<int>result;

void DFS(int source)
{
    cout<<"Visiting node: "<<source<<endl;
    color[source]="GRAY";
    for(int i=0;i<Node_Vec[source].size();i++)
    {
        int v=Node_Vec[source][i];
        if(color[v]=="WHITE")
            DFS(v);
    }
    result.push_back(source);
}

int main()
{
    int nodes,edges;
    cout<<"Number of nodes: ";
    cin>>nodes;
    cout<<"Number of edges: ";
    cin>>edges;

    int nodeA,nodeB;
    for(int i=0;i<edges;i++)
    {
        cin>>nodeA>>nodeB;
        Node_Vec[nodeA].push_back(nodeB);
    }

    for(int i=1;i<=nodes;i++)
    {
        if(color[i]=="WHITE")
            DFS(i);
    }

    reverse(result.begin(),result.end());

    cout<<"Topological order: ";
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
