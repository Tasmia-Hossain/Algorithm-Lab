#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
//vector<pair<int,int>>myVector;
vector<pii>myVector;

bool compSec(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

bool greaterFirst(int a,int b)
{
    return a>b;
}

bool keyCount(int node)
{
    if(node==5)
        return true;
    return false;
}

int main()
{
    vector<int>testVec;
    for(int k=0;k<10;k++)
    {
        testVec.push_back(k);
    }
    cout<<"Before sort fun call"<<endl;
    for(int k=0;k<10;k++)
    {
        cout<<testVec[k]<<" ";
    }
    cout<<endl;

    sort(testVec.begin(),testVec.end(),greaterFirst);
    cout<<endl<<"After sort fun call"<<endl;
    for(int k=0;k<10;k++)
    {
        cout<<testVec[k]<<" ";
    }
    cout<<endl;

    int countNODE,cN;
    countNODE=count(testVec.begin(),testVec.end(),1);
    cN=count_if(testVec.begin(),testVec.end(),keyCount);
    cout<<endl<<countNODE<<" "<<cN;

}
