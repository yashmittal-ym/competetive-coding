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
        map<T,bool>visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T node=q.front();
            q.pop();
            cout<<node;
            for(auto nbr:mp[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }

};

int main(){
    graph<int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    cout<<"hennllo";
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,0);
    g.addEdge(4,5);
    g.bfs(0);
    
}