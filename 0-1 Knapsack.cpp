#include<bits/stdc++.h>
using namespace std;

void Knapsack(int W,int n,vector<int>&weight,vector<int>&benefit,vector<int>&includedItems)
{
    vector<vector<int>>V(n+1,vector<int>(W+1,0));
    for(int w=0;w<=W;w++)
    {
        V[0][w]=0;
    }
    for(int i=1;i<=n;i++)
    {
        V[i][0]=0;
        for(int w=1;w<=W;w++)
        {
            if(weight[i-1]<=w)
            {
                if(benefit[i-1]+V[i-1][w-weight[i-1]]>V[i-1][w])
                {
                    V[i][w]=benefit[i-1]+V[i-1][w-weight[i-1]];
                }
                else
                {
                    V[i][w]=V[i-1][w];
                }
            }
            else
            {
                V[i][w]=V[i-1][w];
            }
        }
    }
    cout<<"Maximum value in knapsack: "<<V[n][W]<<endl;

    int i=n,w=W;
    while(i>0 && w>0)
    {
        if(V[i][w]!=V[i-1][w])
        {
            includedItems[i-1]=1;
            w=w-weight[i-1];
        }
        --i;
    }

    cout<<"Selected items (X): ";
    for(int j=0;j<n;j++)
    {
        cout<<includedItems[j]<<" ";
    }
    cout<<endl;
}

int main()
{
    int W,n;
    cout<<"Enter the knapsack capacity (W): ";
    cin>>W;

    cout<<"Enter number of items (n): ";
    cin>>n;

    vector<int>weight(n);
    vector<int>benefit(n);
    vector<int>includedItems(n,0);

    cout<<"Enter the weights of the items: ";
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }

    cout<<"Enter the benefits of the items: ";
    for(int i=0;i<n;i++)
    {
        cin>>benefit[i];
    }
    Knapsack(W,n,weight,benefit,includedItems);
    return 0;
}

/*

Enter the knapsack capacity (W): 5
Enter number of items (n): 4
Enter the weights of the items: 2 3 4 5
Enter the benefits of the items: 3 4 5 6

Maximum value in knapsack: 7
Selected items (X): 1 1 0 0

*/
