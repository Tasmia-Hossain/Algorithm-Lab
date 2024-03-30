#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,char>p;
    p.first=1;
    p.second='a';
    cout<<"Pair contents: "<<p.first<<" "<<p.second<<endl;

    //**********vector pair**********
    vector<pair<int,char>>vp;
    for(int i=0;i<5;i++)
    {
        vp.push_back(make_pair(i,'A'+1));
    }
    cout<<"Vector pair contents: "<<endl;
    for(int i=0;i<vp.size();i++)
    {
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }

    //**********vector of pairs of pair**********
    vector<pair<int,pair<char,char>>>vpp;
    for(int i=0;i<5;i++)
    {
        vpp.push_back(make_pair(i,make_pair('A'+i,'A'+i+5)));
    }
    cout<<"Vector of pairs of pair contents: "<<endl;
    for(int i=0;i<vpp.size();i++)
    {
        cout<<vpp[i].first<<" "<<vpp[i].second.first<<" "<<vpp[i].second.second<<endl;
    }
}
