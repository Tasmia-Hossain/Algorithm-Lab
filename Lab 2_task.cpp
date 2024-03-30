#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>> Node_Vec[4];

int main()
{
    int node=4;
    int edge=3;

    int nodeA,nodeB,weight;
    for(int i=1;i<=edge;i++)
    {
        cin>>nodeA>>nodeB>>weight;
        Node_Vec[i].push_back({{nodeA,nodeB},weight});
    }
    for(int i=1;i<=edge;i++)
    {
            cout<<Node_Vec[i][0].first.first<<" "<<Node_Vec[i][0].first.second<<Node_Vec[i][0].second<<endl;
    }
        cout<<endl;

        return 0;
}
