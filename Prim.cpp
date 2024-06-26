#include<bits/stdc++.h>
using namespace std;

int p[100];
int weight[100];
int c[100];

void initialize(int v,int s)
{
    for(int i=1;i<=v;i++)
    {
        weight[i]=INT_MAX;
        p[i]=NULL;
    }
    weight[s]=0;
}

void prim(vector<pair<int, int> >g[],int n,int e,int s)
{
    initialize(n,s);
    priority_queue<pair<int, int>>q;

    q.push(make_pair(0,s));

    while(!q.empty())
    {

        int u=q.top().second;
        q.pop();

        for(int i=0; i<g[u].size();i++)
        {
            int v=g[u][i].first;
            int w=g[u][i].second;

            if(weight[v]>w)
            {
                weight[v]=w;
                p[v]=u;
                q.push(make_pair(-weight[v],v));
            }
        }
    }

    int cost=0;
    cout<<"{ ";
    for(int i=1;i<=n;i++)
    {
        cout<<"("<< p[i]<<", "<<i <<")";
        cost+=weight[i];
    }
    cout<<" }"<<endl;

    cout<<"Cost: "<<cost;
    c[s]=cost;
}

int main()
{
    int N;
    int e,r;

    cout<<"Number of nodes: ";
    cin>>N;
    cout<<"Number of edges: ";
    cin>>e;

    vector<pair<int, int> >v[N + 1];

    cout<<"Source : Destination : Weight"<<endl;
    for(int i=0; i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        v[a].push_back(make_pair(b,c));
    }

    for(int i=1;i<=N;i++)
    {
        prim(v,N,e,i);
        cout<<endl;
    }

    int small=INT_MAX;
    int no;
    cout<<"Cost of all nodes: ";
    for(int i=1; i<=N;i++)
    {
        cout<<c[i]<<" ";
        if(c[i]<small)
        {
            small=c[i];
            no=i;
        }
    }

    cout<<endl;
    cout<<"Smallest mst is from node: "<<no;
    return 0;
}

/*
Number of nodes: 8
Number of edges: 9

Source : Destination : Weight
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 2

*/
