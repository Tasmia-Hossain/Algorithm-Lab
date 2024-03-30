#include<bits/stdc++.h>
using namespace std;
vector<int>A;

void Insertion_sort(vector<int>&A,int n)
{
    n=A.size();
    for(int i=1;i<=n-1;i++)
    {
        int key=A[i];
        int j=i-1;
        while(A[j]>key && j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

void Merge(int low,int mid,int hi)
{
    int m=mid-low+1;
    int n=hi-mid;
    int L[m+1],R[n+1];
    int i,j;
    for(i=0;i<=m-1;i++)
    {
        L[i]=A[low+i];
    }
    for(j=0;j<=n-1;j++)
    {
        R[j]=A[mid+j+1];
    }
    L[m]=INT_MAX;
    R[n]=INT_MAX;
    i=j=0;
    for(int k=low;k<=hi;k++)
    {
        if (L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}

void Merge_sort(int low,int hi,vector<int>A,int n)
{
    int c=n;
    if(low<hi)
    {
        if(c==n/2)
        {
            Insertion_sort(A,c);
        }
        else
        {
            int mid=(low+hi)/2;
            Merge_sort(low,mid,A,n);
            Merge_sort(mid+1,hi,A,n);
            Merge(low,mid,hi);
            c--;
        }
    }
}

int main()
{
    int x,n;
    cout<<"Number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        A.push_back(x);
    }
    Merge_sort(0,A.size()-1,A,n);
    cout<<"After Sorting: ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
