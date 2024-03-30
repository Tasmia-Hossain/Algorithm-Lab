#include<bits/stdc++.h>
using namespace std;

int main()
{
    //template_name<data_type> var_name;
    //vector<int>A;
    vector<int>A(10,100);   //A(size,default value 100 assign)
    cout<<"Size of A: "<<A.size()<<endl;

    if(A.empty())
    {
        cout<<"A is empty"<<endl;   //Graph related problem e lage. sob node visit hoye gele empty hoye jabe.
    }

//    for(int i=0; i<5; i++)
//    {
//        A.push_back(i+1);
//    }

//    A[3]=40;
//    A.at(4)=50;
    for(int i=0; i<A.size(); i++)
    {
        //cout<<A[i]<<"\t";
        cout<<A.at(i)<<"\t";
    }
    cout<<endl;

    for(int i=0; i<10; i++)
    {
        //A[i+1]=i+3;
        A[i]=i+1;
    }
//    A.resize(10);
//   A.shrink_to_fit();         //Benefits: size ja ache tar cheye besi access korte parbe na. besi print korte chaile garbage value dibe.
//    A.insert(A.begin(),55);       //shurute 55 ashbe, baki value gulo right shift hobe
    A.insert(A.begin() + 3 , 5 , 99);       //insert(index no,how many times,value
    for(auto itr = A.begin() ; itr != A.end() ; itr++)    //iteration
    {
        cout<<*itr<<"\t";
    }
//    for(int i=0; i<A.size(); i++)
//    {
//        cout<<A[i]<<"\t";
//    }
//        for(int i=0; i<15; i++)
//        {
//            cout<<A[i]<<"\t";
//        }
    cout<<endl;
    //cout<<"Size of A: "<<A.size()<<endl;
    //cout<<"Maximum Size of A: "<<A.max_size()<<endl;    //max_size() er value size() theke olpo kichu besi hoy

    vector<int>V;
    V.insert(V.begin() , A.begin()+2 , A.end()-3);
    for(auto itr = V.begin() ; itr != V.end() ; itr++)
    {
        cout<<*itr<<"\t";
    }
    cout<<endl;

    V.pop_back();
    for(auto itr = V.begin() ; itr != V.end() ; itr++)
    {
        cout<<*itr<<"\t";
    }
    cout<<endl;

    V.erase(V.begin()+1,V.begin()+5);
    for(auto itr = V.begin() ; itr != V.end() ; itr++)
    {
        cout<<*itr<<"\t";
    }
    cout<<endl;

    //V.clear();
    //sort(V.begin(),V.end());
    sort(V.begin() , V.end() , greater<>());    //reverse order (greater er jaygay kono function pass kora jabe ja age lekhe nite hobe)
    for(auto itr = V.begin() ; itr != V.end() ; itr++)
    {
        cout<<*itr<<"\t";
    }
    cout<<endl;

    vector<int>B;
    //Value copy korar way:
    // 1
//    for(int i=0; i<A.size(); i++)
//    {
//        B.push_back(A.at(i));
//    }

    // 2
//    B = A;

    //3
//    B.insert(B.begin(),A.begin(),A.end());

    //4
//    A.assign(B.begin(),B.end());    //B vector ta A vector e assign hoye jabe


}
