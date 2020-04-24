#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    map<T,list<T>>mp;
    public:
    void addEdge(T x,T y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    void bfs(T src){
        map<T,int>visited;
        queue<T> q;

        for(auto node_pair:mp){
            visited[node_pair.first]=INT_MAX;
            
        }
        q.push(src);
        visited[src]=0;

        while(!q.empty()){
            T node=q.front();
            q.pop();
            for(auto nbr:mp[node]){
                if(visited[nbr]==INT_MAX){
                    q.push(nbr);
                    visited[nbr]=visited[node]+1;
                }
            }
        }
        for(auto x : mp){
            cout<<x.first<<"-->"<<visited[x.first]<<endl;;
        }

        // for(auto x : visited){                                   this will also print the same result
        //     cout<<x.first<<"-->"<<x.second<<endl;;
        // }
    }

};

int main(){
    graph<int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,0);
    g.addEdge(4,5);
    g.bfs(0);
    
}