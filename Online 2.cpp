#include<bits/stdc++.h>
using namespace std;

int Tri_search(vector<int>A,int k)
{
    int low=0;
    int hi=A.size()-1;

    while(low<=hi)
    {
        int mid=(low+hi)/3;
        int mid2=(mid+hi)/2;
        if(A[mid]==k || A[mid2]==k)
            return 1;
        else if(A[mid]<k)
            low=mid+1;
        else if(A[mid]>k && A[mid2]<k)
        {
            low=mid+1;
            hi=mid2-1;
        }
        else
            hi=mid2-1;
    }
    return -1;
}

int main()
{
    vector<int>v;
    int x,n;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    int ans=Tri_search(v,10);
    if(ans==1)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
}
