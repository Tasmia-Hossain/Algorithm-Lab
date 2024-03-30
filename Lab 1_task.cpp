#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>A;
    for(int i=1;i<11;i++)
    {
        A.push_back(i*10);
    }
    for(auto i=A.rbegin();i!=A.rend();i++)
        cout<<*i<<" ";
}
