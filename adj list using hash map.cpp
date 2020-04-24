#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<string,list<pair<string,int>>>mp;
    //map<string,list<pair<string,int>>>mp;   -->can use this also
    void insertData(string x,string y,bool bidi,int value){
        mp[x].push_back(make_pair(y,value));
        if(bidi){
            mp[y].push_back(make_pair(x,value));
        }
    }

    void print(){
        for(auto x:mp){
            string node=x.first;
            cout<<node<<" :: ";
            list<pair<string,int>> nbrs=x.second;
            for(auto nbr:nbrs){
                    string dest=nbr.first;
                    int value=nbr.second;
                    cout<<dest<<"->"<<value<<" , ";
            }cout<<endl;
        }
    }

};

int main(){
    graph g;
    g.insertData("A","B",true,20);
    g.insertData("A","C",true,10);
    g.insertData("A","D",false,50);
    g.insertData("D","B",true,40);
    g.insertData("C","D",true,30);
    g.print();
}