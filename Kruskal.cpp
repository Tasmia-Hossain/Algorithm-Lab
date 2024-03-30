#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int , pair<int, int> > >q;
int s[100];

void sort_edges(vector<pair<int, int> >v[],int n)
{
    for(int i=1; i<=n;i++)
    {
        for(int j=0; j<v[i].size();j++)
        {
            q.push(make_pair(-v[i][j].second,make_pair(i, v[i][j].first)));
        }
    }
}

void MakeSet(int v)
{
    s[v]=v;
}

int FindSet(int x)
{
    return (s[x]==x)?x : s[x]=FindSet(s[x]);
}

void uni(int u,int v,int n)
{
    int rootU=FindSet(u);
    int rootV=FindSet(v);

    s[rootU]=rootV;
}

void Kruskal(vector<pair<int, int> >v[],int n,int e)
{
    vector<pair<int, int> >T;
    for(int i=1;i<=n;i++)
        MakeSet(i);
    sort_edges(v, n);
    int cost=0;
    while(!q.empty())
    {
        pair<int, int>p;
        int w=-q.top().first;
        p=q.top().second;
        q.pop();

        int u=p.first;
        int v=p.second;

        if(FindSet(u)!=FindSet(v))
        {
            T.push_back(make_pair(u, v));
            uni(u,v,n);

            cost+=w;
        }
    }

    cout<<"{ ";
    for(int i=0;i <T.size();i++)
    {
        cout<<"("<<T[i].first<<", "<<T[i].second<<")";
    }
    cout<<" }"<<endl;

    cout<<"Cost: "<<cost;
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
    for(int i=0; i< e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        v[a].push_back(make_pair(b,c));
    }

    Kruskal(v,N,e);
    return 0;
}

/*
Input:
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

Output:
{ (7, 8)(8, 5)(4, 3)(3, 5)(1, 2)(2, 3)(6, 7) }
Cost: 28

*/
