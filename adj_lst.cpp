#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    public:
        unordered_map<T,list<T>>adj;

        void addEdge(T u,T v,bool direction){
            //* direction=0 undirected
            //* direction=1 directed
            adj[u].push_back(v);
            if(!direction){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto a:i.second){
                    cout<<a<<" ";
                }cout<<endl;
            }
        }
};

int main(){

    // int n;
    // cout<<"enter no of nodes"<<endl;
    // cin>>n;
    
    // int e;
    // cout<<"enter no of edges"<<endl;
    // cin>>e;
    graph <int>g;
    // for(int i=0; i<e; i++){
    //     int u,v;
    //     cout<<"enter edges"<<endl;
    //     cin>>u>>v;
    //     g.addEdge(u,v,0);
    // }
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,1,0);
    g.addEdge(3,4,0);
    g.addEdge(0,4,0);

    g.printAdjList();
    
    return 0;
}